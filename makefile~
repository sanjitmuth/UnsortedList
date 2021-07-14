main: Student.cpp UnsortedList.cpp UnsortedListDriver.cpp
	g++ -o UnsortedListDriver UnsortedList.cpp UnsortedListDriver.cpp
Student.o: Student.cpp
	g++ -c Student.cpp
UnsortedList.o: UnsortedList.cpp
	g++ -c UnsortedList.cpp
UnsortedListDriver.o: UnsortedListDriver.cpp
	g++ -c UnsortedListDriver.cpp
run: UnsortedListDriver
	./UnsortedListDriver
clean:
	rm -rf UnsortedListDriver
	rm -rf * .o
