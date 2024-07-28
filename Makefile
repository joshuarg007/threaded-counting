# Define the C++ compiler to use
CXX = g++

# Define the name of the target executable
TARGET = threaded_counting

# Define the source file(s)
SRCS = ThreadedCounting.cpp

# Build the target executable from the source file(s)
$(TARGET): $(SRCS)
	$(CXX) -std=c++11 -o $(TARGET) $(SRCS)

# Declare the clean target and remove build artifacts
.PHONY: clean

clean:
	rm -f $(TARGET)
