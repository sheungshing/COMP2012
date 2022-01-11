CPPFLAGS = -std=c++11
all: mainReception.exe mainInfo.exe mainTips.exe

mainReception.exe: gym.o swimmingpool.o seafront.o handbook.o mainReception.cpp
	g++ -o $@ $(CPPFLAGS) gym.o swimmingpool.o seafront.o handbook.o mainReception.cpp

mainInfo.exe: gym.o swimmingpool.o seafront.o mainInfo.cpp
	g++ -o $@ $(CPPFLAGS) gym.o swimmingpool.o seafront.o mainInfo.cpp

mainTips.exe: gym.o seafront.o mainTips.cpp
	g++ -o $@ $(CPPFLAGS) gym.o seafront.o mainTips.cpp


%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	del  *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
