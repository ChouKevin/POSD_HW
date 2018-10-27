.PHONY: clean
TARGET = bin/hw3
all: $(TARGET)
test_file = test/*
src_file = src/*
$(TARGET): $(test_file) $(src_file)
	g++ -std=c++11 src/main.cpp -o $(TARGET) -lgtest -lpthread
clean:
	rm bin/hw3
