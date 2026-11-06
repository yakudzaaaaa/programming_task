CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = main
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp DynamicArray.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

asan: $(SRCS)
	$(CXX) $(CXXFLAGS) -fsanitize=address -static-libasan -g $(SRCS) -o main_asan

clean:
	rm -f $(OBJS) $(TARGET) main_asan

.PHONY: all clean asan