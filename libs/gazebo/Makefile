CXX= /usr/local/gcc-5.4/bin/g++
CXXFLAGS= -std="c++11" -w
CXXLIBS= -I /usr/include/sdformat-5.1 -I /usr/include/gazebo-8 -I /usr/include/ignition/math3 -I /usr/include/ignition/msgs0
INCLUDE_PATH="/usr/include/gazebo-8 /usr/include/sdformat-4.0/sdf/sdf.hh"
EXPORT_PATH= export CPLUS_INCLUDE_PATH=$(INCLUDE_PATH):$$CPLUS_INCLUDE_PATH ;
LIBS= -lgazebo_transport -lgazebo_physics -lgazebo_sensors -lgazebo_rendering -lgazebo_gui -lgazebo_client -lgazebo_msgs -lgazebo_math -lgazebo_common -lgazebo -lboost_thread -lboost_signals -lboost_system -lboost_filesystem -lboost_program_options -lboost_regex -lboost_iostreams -lboost_date_time -lboost_chrono -lboost_atomic -lsdformat -ltbb -lignition-transport3 /usr/lib64/libignition-msgs0.so.0.7.0 -lprotobuf -lpthread -lsdformat /usr/lib64/libignition-math3.so.3.0.0 -ltbb -lignition-transport3 -lprotobuf -lpthread -lprotobuf
PICXX= $(wildcard PI/*.cpp)


telem_test:
	g++ $(CXXFLAGS) $(CXXLIBS) -o $@ $@.cpp telem_interface.cpp EncoderMsg.pb.cc $(LIBS)


motors_test:
	g++ $(CXXFLAGS) $(CXXLIBS) -o $@ $@.cpp control_interface.cpp MotorsCommand.pb.cc $(LIBS)


control_test: control_test.cpp
	g++ $(CXXFLAGS) $(CXXLIBS) -o $@ $@.cpp telem_interface.cpp EncoderMsg.pb.cc control_interface.cpp MotorsCommand.pb.cc ../timer/mTimer.cpp Motor.cpp $(PICXX) $(LIBS)
