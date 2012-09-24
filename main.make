Main.cc : Main.o Stack.o
	g++ -o Main.cc Main.o Stack.o

# above, we are saying main.cc depends on main.o and stack.o
# and to create main.cc we give the g++ command as shown on the next line

# which starts with a TAB although you cannot see that . 
# note that the command : g++ -o main.cc main.o stack.o
# creates an executable file named main.cc from the 2 object files respectively. 

Main.o: Main.cpp Stack.h
	g++ -c Main.cpp

# above we are saying main.o depends on Main.cpp and Stack.h
# and to compile only Main.cpp if and only if Main.cpp or Stack.h 
# have changed since the last creation of main.o 

Stack.o : Stack.h Stack.cpp
	g++ -c Stack.cpp

# above we are saying stack.o depends on Stack.h and Stack.cpp
# so if either Stack.h or Stack.cpp CHANGED since creating stack.o 
# comple Stack.cpp again 

clean : &nbps rm *.o Main.cc

# above we are stating how to run the rule for clean, no dependencies, 
# what we want is when we ask to do a "make -f main.make clean" 
# that will not do anything except remove executable and object files 
# so we can "clean out" our directory of unneeded large files. 
# we only do a make clean when we want to clean up the files.

#END 
