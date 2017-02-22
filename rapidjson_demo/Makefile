# Makefile

RM = rm -f
CXX = g++
CFLAGS = -Wall -g
INCLUDE = -I./rapidjson/include
LDFLAGS = 
LDPATH = 

PROGS =	tutorial array read_write read write

.PHONY: all
all: $(PROGS)
	@echo "build OK!"

clean:
	@$(RM) $(PROGS) *.o
	@echo "clean OK!"

%.o:%.cpp
	$(CXX) -o $@ -c $< $(CFLAGS) $(INCLUDE)

tutorial: tutorial.o
	$(CXX) -o $@ $^ $(LDFLAGS) $(LDPATH)

array: array.o
	$(CXX) -o $@ $^ $(LDFLAGS) $(LDPATH)

read_write: read_write.o
	$(CXX) -o $@ $^ $(LDFLAGS) $(LDPATH)

read: read.o
	$(CXX) -o $@ $^ $(LDFLAGS) $(LDPATH)

write: write.o
	$(CXX) -o $@ $^ $(LDFLAGS) $(LDPATH)

