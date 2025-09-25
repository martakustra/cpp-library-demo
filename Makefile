CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SRC = src/Book.cpp src/Library.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = app

all: $(TARGET)

$(TARGET) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)