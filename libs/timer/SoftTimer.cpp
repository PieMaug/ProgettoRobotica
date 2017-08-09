#include "SoftTimer.h"


SoftTimer::SoftTimer(int t, Func f){
	set_time(t);
	set_func(f);
}


SoftTimer* SoftTimer::get_timer(int t, Func f){
	if(singleton_timer == NULL){
		singleton_timer = new SoftTimer(t,f);
	}
	return singleton_timer;
}

void SoftTimer::set_time(int t){
	t_time = t;
}

void SoftTimer::set_func(Func f){
	function = f;
}

void SoftTimer::start(){
	signal(SIGALRM,sing_handler);
	alarm(t_time);
}

int SoftTimer::get_time(){
	return t_time;
}

Func SoftTimer::get_func(){
	return function;
}
