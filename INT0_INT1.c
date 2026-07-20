#include <reg51.h>

sbit in1=P2^0;
sbit in2=P2^1;
sbit en1=P2^2;

sbit led1=P3^0;
sbit led2=P3^1;

unsigned int count=0;
unsigned char state=0;

void forward();
void stop();
void reverse();

void main()
{
	TMOD=0x01;
	
	TH0=0xFC;
	TL0=0x18;
	
	TR0=1;
	
	IE=0x83;
	
	IT0=1;
	
	en1=1;
	
	forward();
	
	while(1);
}

void ISR_ex0(void) interrupt 0
{
	if(state==0)
	{
		stop();
		
		state=1;
	}
	else if(state==1)
	{
		reverse();
		
		state=2;
	}
	else if(state==2){
		stop();
		state=3;
	}
	else{
		forward();
		
		state=0;
	}
}

void timer(void) interrupt 1
{
	TH0=0xFC;
	TL0=0x18;
	
	count++;
	
	if(count>=2000)
	{
		led1=~led1;
		led2=~led2;
		
		count=0;
	}
}

void forward()
{
	in1=1;
	in2=0;
}

void stop()
{
	in1=0;
	in2=0;
}

void reverse()
{
	in2=1;
	in1=0;
}
