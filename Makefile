CC=g++
INCLUDE_DIR := $(MNIST_ML_ROOT)/include
SRC := $(MNIST_ML_ROOT)/src
CFLAGS := -std=c++11 -g
LIB_DATA := libdata.so

all : $(LIB_DATA)

$(LIB_DATA) : libdir objdir obj/data_handler.o obj/data.o
	$(CC) $(CFLAGS) -o $(MNIST_ML_ROOT)/lib/$(LIB_DATA) obj/*.o
	rm -r $(MNIST_ML_ROOT)/obj

libdir:
	mkdir -p $(MNIST_ML_ROOT)/lib

objdir:
	mkdir -p $(MNIST_ML_ROOT)/obj

obj/data_handler.o : $(SRC)/data_handler.cc
	$(CC) -fPIC $(CFLAGS) -o obj/data_handler.o -c $(SRC)/data_handler.cc -I$(INCLUDE_DIR)

obj/data.o : $(SRC)/data.cc
	$(CC) -fPIC $(CFLAGS) -o obj/data.o -c $(SRC)/data.cc -I$(INCLUDE_DIR)

clean:
	rm -r $(MNIST_ML_ROOT)/lib
	rm -r $(MNIST_ML_ROOT)/obj

