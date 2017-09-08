#ifndef TIMERMIL
#define TIMERMIL

#include <pthread.h>

class Timer{
	public:
		Timer();
		int get_interupt();
	private:	
		int interupt;
		
};



#endif
