# A line starting with a hash is a comment, we'll build up
# the below example
 
TARGET = main
SRC_FILES = main.cpp build.cpp part.cpp

# DO NOT EDIT BELOW HERE
CXX = g++
#CFLAGS = -Wall -g -std=c++11  Turned off warning because we will create many unused arrays
CFLAGS = -g -std=c++11
OBJECTS = $(SRC_FILES:.cpp=.o)
ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)

# DEPENDENCIES
main.o: main.cpp 
build.o: build.cpp build.h part.cpp part.h
part.o: part.cpp part.h
