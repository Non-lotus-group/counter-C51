#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit dula=P2^6;
sbit wela=P2^7;
uchar code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,
                                  0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
uint num,num1,num2,num3,num4;
void delay(uint);
void display(uchar qian,uchar bai,uchar shi,uchar ge)
{
dula=1;
P0=table[qian];
dula=0;
P0=0xff;
wela=1;
P0=0xfe;
wela=0;
delay(5);

dula=1;
P0=table[bai];
dula=0;
P0=0xff;
wela=1;
P0=0xfd;
wela=0;
delay(5);

dula=1;
P0=table[shi];
dula=0;
P0=0xff;
wela=1;
P0=0xfb;
wela=0;
delay(5);

dula=1;
P0=table[ge];
dula=0;
P0=0xff;
wela=1;
P0=0xf7;
wela=0;
delay(5);
}
void delay(uint xms)
{
uint i,j;
for(i=xms;i>0;i--)
       for(j=40;j>0;j--);
}

uint read()
{
uchar tl,th1,th2;
uint val;
while(1)
      {
      th1=TH0;
      tl=TL0;
      th2=TH0;
      if(th1==th2)
      break;
      }
val=th1*256+tl;
return val;
}

void main()
{
uchar a,b,c,d;

TMOD=0x15;
TH0=0;
TL0=0;
TH1=(65536-45872)/256;
TL1=(65536-45872)%256;
EA=1;
ET0=1;
ET1=1;
TR0=1;
TR1=1;
num1=0;
num2=0;
num3=0;
num4=0;
num=0;


while(1)
     {
	 if(num2==100)
       {
	    num2=0;
		num1=num;
		num=read();
		num3=num-num1;
       	num4=num3*6;
        a=num4/1000;
        b=num4%1000/100;
        c=num4%100/10;
        d=num4%10; 
	    }

     display(a,b,c,d);
	
     }
}

void T1_time()interrupt 3
{
TH1=(65536-45872)/256;
TL1=(65536-45872)%256;
num2++;

}
