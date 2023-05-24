appname := myapp

CXX := g++
CXXFLAGS := -Wall -g

# Boost library directory
BOOST_LIB_DIR = /usr/lib/

# Boost libraries
BOOST_LIBS := -lboost_system -lboost_thread -lboost_filesystem

srcfiles := $(shell find . -maxdepth 1 -name "*.cpp")
objects  := $(patsubst %.cpp, %.o, $(srcfiles))

all: $(appname)

$(appname): $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(appname) $(objects) -L$(BOOST_LIB_DIR) $(BOOST_LIBS) $(LDLIBS)

depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	rm -f $(objects)

dist-clean: clean
	rm -f *~ .depend

include .depend
