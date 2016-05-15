CXX=g++
CXXFLAGS=-pthread `pkg-config --cflags opencv` -g -Wall -pedantic -std=c++11
LXXFLAGS=-pthread `pkg-config --libs opencv` -std=c++11
OBJS=videoreader.o imageprocessing.o haarcascadeclasifier.o main.o

all: uav_raspberry
	
	
uav_raspberry: $(OBJS)
	$(CXX)  $^ -o $@ $(LXXFLAGS)
	
$(OBJS): %.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@
	
clean:
	rm -f $(OBJS) uav_raspberry
