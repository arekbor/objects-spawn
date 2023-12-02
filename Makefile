TARGET = main
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
INCLUDES = src/object.cpp

all:
	g++ -o bin/$(TARGET) src/main.cpp $(LIBS) $(INCLUDES)
	bin/$(TARGET)