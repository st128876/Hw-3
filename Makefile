CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = hw3

SRCS = Source.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) $(OBJS)

