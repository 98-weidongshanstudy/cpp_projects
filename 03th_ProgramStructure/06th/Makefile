CFLAGS = -g -Wall

main: main.o person.o dog.o
	g++ ${CFLAGS} -o $@ $^

%.o : %.cpp
	g++ ${CFLAGS} -c -o $@ $<

clean:
	del *.o *.exe	