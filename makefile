CPP = g++
PROG = fint
FLAGS = -std=c++11
OBJS = real_function.o driver.o polynomial.o

$(PROG):	$(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $@
	
%.o : %.c
	$(CPP) -c $(FLAGS) $< -g -c -o $@

clean:
	rm -rf $(PROG) *.o
	

#dependency chains
real_function.o:	real_function.cpp real_function.h
driver.o:	driver.cpp real_function.h polynomial.h
polynomial.o:	polynomial.cpp polynomial.h

