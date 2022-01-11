CPPFLAGS = -std=c++11

all: decimal.exe

decimal.exe: decimal.o main.cpp
	g++ -o $@ $(CPPFLAGS) decimal.o main.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	del *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
