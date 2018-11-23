CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

all: SPQ UPQ heap

SPQ: main.cpp SPQ.h
	$(CXX) $(CXXFLAGS) -D"Queue=PriorityQueue" -o $@ $<

UPQ: main.cpp UPQ.h
	$(CXX) $(CXXFLAGS) -D"Queue=UnsortedPriorityQueue" -o $@ $<

heap: main.cpp heap.h
	$(CXX) $(CXXFLAGS) -D"Queue=HeapPriorityQueue" -o $@ $<

run%: %
	@./$<

clean:
	$(RM) SPQ UPQ heap