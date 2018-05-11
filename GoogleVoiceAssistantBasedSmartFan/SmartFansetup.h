///////////////////////////////////////////////
//
//
//  BY HariYogesh
//
//
//
//
//
/////////////////////////////////////////////////



#ifndef _SmartFansetup_H_
#define _SmartFansetup_H_

#define slow_on write(portb,0,l) //blue
#define slow_off write(portb,0,h)

#define medium_on write(portb,1,l)//yellow
#define medium_off write(portb,1,h)

#define fast_on write(portb,4,l)//orange
#define fast_off write(portb,4,h)

void slow()
{ 
	medium_off;
	fast_off;
	slow_on;
}
void  medium()
{ 
	medium_on;
	fast_off;
	slow_off;
}
void  fast()
{ 
	medium_off;
	fast_on;
	slow_off;
}
void  fan_off()
{ 
	medium_off;
	fast_off;
	slow_off;
}



#endif 