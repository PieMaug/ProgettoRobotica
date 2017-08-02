#ifndef SOFTTIMER
#define SOFTTIMER

#include <signal.h>
#include <unistd.h>

typedef void(*Func)(void);
class SoftTimer;
static SoftTimer* timer = NULL;

static void sing_handler(int);

class SoftTimer{
	protected:
		SoftTimer(int, Func);
	private:
		int t_time;
		Func function;
	public:
		static SoftTimer* get_timer(int t, Func f);
		void set_time(int t);
		void set_func(Func f);
		void start();
		int get_time();
		Func get_func();
	
};


static void sing_handler(int){
	if(timer != NULL){
		(timer->get_func())();
		alarm(timer->get_time());
	}
}

#endif
