CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = gf2m_modular_inverse
SRC = gf2m_modular_inverse.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe

.PHONY: all run clean
