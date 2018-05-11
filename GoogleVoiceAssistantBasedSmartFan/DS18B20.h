////////////
//digitlabz
///////////


#ifndef DS18B20_H
#define DS18B20_H

#define uchar unsigned char
#define uint unsigned int


unsigned char pds18,bds18;


unsigned char sx (unsigned char x,unsigned char a)
{
     switch (x)                                                                  ////////////////////////////////
    {                                                                           ////////////////////////////////
		case (1): 
		 #ifdef DDRA
		return ((PINA) & (1<<a));
		 #endif
            break; 
			
		case (2):
		 return ((PINB) & (1<<a));
 
            break; 
		case (3):
			return ((PINC) & (1<<a));
		  
            break; 
		case (4): 
		 return ((PIND) & (1<<a));
            break; 


}
 
 
 }

void dx(unsigned char x,unsigned char a,unsigned char y)
{
     switch (x)                                                                  ////////////////////////////////
    {                                                                           ////////////////////////////////
		case (1): 
		  #ifdef DDRA
		  if(y==1)
		  {
		     DDRA&=(~(1<<a));
		        
		  }
		  else{
		     DDRA|=(1<<a);
		  }		
		 #endif
            break; 
			
		case (2):
		  if(y==1)
		  {
		     DDRB&=(~(1<<a));
		        
		  }
		  else{
		     DDRB|=(1<<a);
		  }		
 
            break; 
		case (3):

		  if(y==1)
		  {
		     DDRC&=(~(1<<a));
		        
		  }
		  else{
		     DDRC|=(1<<a);
		  }		 
            break; 
		case (4): 

		  if(y==1)
		  {
		     DDRD&=(~(1<<a));
		        
		  }
		  else{
		     DDRD|=(1<<a);
		  }				
            break; 


}
 
 
 }


void ds18b_init(unsigned char port,unsigned char bit)
{

pds18 = port;
bds18 = bit;
init_ds18b20();

}







// Start transaction with 1-wire line. 
void init_ds18b20(void)
 { dx(pds18,bds18,0); 
   write(pds18,bds18,l) ;    
   _delay_us(600); 
   write(pds18,bds18,h);    
   _delay_us(50);  
   dx(pds18,bds18,1); 
   while(sx(pds18,bds18));
   _delay_us(240); 
   dx(pds18,bds18,0);   
   write(pds18,bds18,h);    
   _delay_us(300); 
 }






uchar readbyte(void)
 { uchar i = 0,data = 0;int yk=bds18,hk=pds18;

   dx(pds18,bds18,0); 
   for (i=0; i<8; i++)
    { write(pds18,bds18,l) ;
      data >>= 1;
      _delay_us(3);
      write(pds18,bds18,h);
     if(hk==1)
	   DDRA&=~(1<<yk);
      else if(hk==2) 
	    DDRB&=~(1<<yk);
		 else if(hk==3) 
	    DDRC&=~(1<<yk);
		 else if(hk==4) 
	    DDRD&=~(1<<yk);
		
      _delay_us(10);
      if(sx(pds18,bds18))
         data |= 0x80;
      dx(pds18,bds18,0);
      write(pds18,bds18,h);
      _delay_us(45);
      _delay_us(5);
    }
   return(data);
 }


void writecommand(uchar data)
 { uchar  i;
   for(i=0; i<8; i++)
    { write(pds18,bds18,l);
      _delay_us(15);    
      if(data & 0x01)
         write(pds18,bds18,h);
      else 
         write(pds18,bds18,l);
      _delay_us(45);
      data >>= 1;
      write(pds18,bds18,h);
      _delay_us(2);
    }
 }



uchar read_temp(void)
 {
uchar a, b, tt;
 uint t;
   init_ds18b20();
  
  
   writecommand(0xCC); 
   writecommand(0x44);
   init_ds18b20(); 
  
   writecommand(0xCC); 
   writecommand(0xBE); 
   a = readbyte();
   b = readbyte();
   t = b;
   t <<= 8;
   t = t|a;
   tt = t*0.0625;
	return(tt);
 }



#endif