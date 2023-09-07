appname := myapp

CXX := g++
CXXFLAGS := -Wall -g

# Boost library directory
# BOOST_LIB_DIR = /path/to/boost/libs

# Boost library directory
BOOST_LIB_DIR := /usr/lib

# Boost libraries
BOOST_LIBS := boost_serialization

srcfiles := $(shell find . -maxdepth 1 -name "*.cpp")
objects  := $(patsubst %.cpp, %.o, $(srcfiles))

all: $(appname)

$(appname): $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS)

depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	rm -f $(objects)

dist-clean: clean
	rm -f *~ .depend

include .depend

# Boost library flags
LDFLAGS += -L$(BOOST_LIB_DIR)

# Boost libraries to link against
LDLIBS += $(addprefix -l, $(BOOST_LIBS))
