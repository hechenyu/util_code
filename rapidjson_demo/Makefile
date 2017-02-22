# Makefile

RM = rm -f
CXX = g++
CFLAGS = -Wall -g
INCLUDE = -I./rapidjson/include
LDFLAGS = 
LDPATH = 

PROGS =	tutorial

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

