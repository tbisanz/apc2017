# Makefile for VideoStore refactoring example

CXX        = g++
LD         = $(CXX)
OPT        = -g

# Environment variable to be set, where gtest is installed
# GTESTPATH = /Users/pia/Documents/g4dev/googletest/gtest_install/

ifeq ($(HOSTNAME), naf-school01.desy.de)
    GTESTPATH=/usr
endif

ifeq ($(HOSTNAME), naf-school02.desy.de)
    GTESTPATH=/usr
endif

GINCS = -I $(GTESTPATH)/include
GLIBS = -L $(GTESTPATH)/lib -lgtest -lpthread

CXXFLAGS   = -Wall $(OPT) -fPIC $(GINCS)

LDFLAGS    =

SOURCES    = Customer.cc Movie.cc Rental.cc
TESTSRC    = testVideoStore.cc
OBJECTS    = $(SOURCES:.cc=.o) $(TESTSRC:.cc=.o)
EXECUTABLE = $(basename $(TESTSRC) )

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(LD) $(LDFLAGS) -o $@ $^ $(GLIBS)
	LD_LIBRARY_PATH=$(PWD) ./$@


clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

