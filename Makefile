# gmake
CXX = g++
CXXFLAGS = -g -Wall
SRCMODULES =  user.cpp message.cpp
OBJMODULES = $(SRCMODULES:.c=.o)

%.o: %.c %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

out: main.cpp $(OBJMODULES)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: out
	./out

clean:
	rm -f *.o out

.PHONY: all run clean
