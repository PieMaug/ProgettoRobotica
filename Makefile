CXX= /usr/local/gcc-5.4/bin/g++
LIBSH= $(wildcard libs/*/*.h)
LIBSCXX= $(wildcard libs/*/*.cpp)
FIRMH= $(wildcard MotionControl_v6/*.h)
FIRMCXX= $(wildcard MotionControl_v6/*.cpp)
CFLAGS= -I libs/timer -I libs/controllib

main: $(LIBSH)
	$(CXX) $(CFLAGS) -o $@ $(LIBSCXX) $(FIRMCXX)
