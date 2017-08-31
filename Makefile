CXX= /usr/local/gcc-5.4/bin/g++
LIBSH= $(wildcard libs/*/*.h)
#LIBSCXX= $(wildcard libs/*/*.cpp)
LIBSCXX= $(shell ls libs/*/*.cpp | grep -v test)
LIBSCC= $(wildcard libs/*/*.cc)
FIRMH= $(wildcard MotionControl_v6/*.h)
FIRMCXX= $(wildcard MotionControl_v6/*.cpp)
CXXFLAGS= -std="c++11" -w
CXXINCLUDES= -Ilibs/gazebo -Ilibs/timer -Ilibs/controllib -I/usr/include/sdformat-5.1 -I/usr/include/gazebo-8 -I/usr/include/ignition/math3 -I/usr/include/ignition/msgs0
GAZLIBS= -lgazebo_transport -lgazebo_physics -lgazebo_sensors -lgazebo_rendering -lgazebo_gui -lgazebo_client -lgazebo_msgs -lgazebo_math -lgazebo_common -lgazebo -lboost_thread -lboost_signals -lboost_system -lboost_filesystem -lboost_program_options -lboost_regex -lboost_iostreams -lboost_date_time -lboost_chrono -lboost_atomic -lsdformat -ltbb -lignition-transport3 /usr/lib64/libignition-msgs0.so.0.7.0 -lprotobuf -lpthread -lsdformat /usr/lib64/libignition-math3.so.3.0.0 -ltbb -lignition-transport3 -lprotobuf -lpthread -lprotobuf



main: $(FIRMCXX) $(LIBSCXX)
	g++ $(CXXFLAGS) $(CXXINCLUDES) -o $@ $(LIBSCXX) $(FIRMCXX) $(LIBSCC) $(GAZLIBS)

clean:
	rm main

prova:
	@echo "LIBSCXX " $(LIBSCXX)
	@echo "FIRMCXX " $(FIRMCXX)
