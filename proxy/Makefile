appname := flyweight
testname := testflyweight

CXX := g++
CXXFLAGS := -Wall -g

# Boost library directory
BOOST_LIB_DIR := /usr/lib
GOOGLE_TEST_LIB_DIR := /home/jerome/clibs/googletestBUILT/lib

# Boost libraries
BOOST_LIBS := boost_serialization boost_thread boost_atomic boost_system
GOOGLE_TEST_LIBS := gtest gtest_main
# GOOGLE_TEST_LIBS := gmock gmock_main gtest gtest_main

srcfiles := $(shell find . -maxdepth 1 -name "*.cpp")
# srcfilesfortest := $(shell find src -maxdepth 1 -name "*.cpp" -not -name "main.cpp")
# testsrcfiles := $(shell find tests -name "*.cpp")
objects  := $(patsubst %.cpp, %.o, $(srcfiles))
# objectsfortest  := $(patsubst %.cpp, %.o, $(srcfilesfortest))
# testobjects := $(patsubst %.cpp, %.o, $(testsrcfiles))

all: compile

.PHONY: compile
compile: $(appname)

$(appname): $(objects) 
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS)

# .PHONY: tests
# tests: compile-tests
# 
# .PHONY: compile-tests
# compile-tests: $(testname)
# 
# $(testname): $(testobjects) $(objects)
# 	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(testname) $(testobjects) $(objectsfortest) $(LDLIBS)

depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	rm -f $(objects) $(testobjects)

dist-clean: clean
	rm -f *~ .depend $(appname) $(testname)

include .depend

# Boost library flags
LDFLAGS += -L$(BOOST_LIB_DIR)
LDFLAGS += -L$(GOOGLE_TEST_LIB_DIR)

# Boost libraries to link against
LDLIBS += $(addprefix -l, $(BOOST_LIBS))
LDLIBS += $(addprefix -l, $(GOOGLE_TEST_LIBS))
LDLIBS += -lstdc++


## works
# appname := myapp
# 
# CXX := g++
# CXXFLAGS := -Wall -g
# 
# # Boost library directory
# # BOOST_LIB_DIR = /path/to/boost/libs
# 
# # Boost library directory
# BOOST_LIB_DIR := /usr/lib
# GOOGLE_TEST_LIB_DIR := /home/jerome/clibs/googletestBUILT/lib 
# 
# # Boost libraries
# BOOST_LIBS := boost_serialization boost_thread boost_atomic boost_system
# GOOGLE_TEST_LIBS := gmock_main gmock gtest_main gtest
# 
# srcfiles := $(shell find . -maxdepth 1 -name "*.cpp")
# objects  := $(patsubst %.cpp, %.o, $(srcfiles))
# 
# all: $(appname)
# 
# $(appname): $(objects)
# 	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS)
# 
# depend: .depend
# 
# .depend: $(srcfiles)
# 	rm -f ./.depend
# 	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;
# 
# clean:
# 	rm -f $(objects)
# 
# dist-clean: clean
# 	rm -f *~ .depend
# 
# include .depend
# 
# # Boost library flags
# LDFLAGS += -L$(BOOST_LIB_DIR)
# LDFLAGS += -L$(GOOGLE_TEST_LIB_DIR)
# 
# # Boost libraries to link against
# LDLIBS += $(addprefix -l, $(BOOST_LIBS))
# LDLIBS += $(addprefix -l, $(GOOGLE_TEST_LIBS))
# 
# # Add C++ standard library
# LDLIBS += -lstdc++
# 
# 
