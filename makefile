main:    main.cpp ArrayStack.o archivo.o 
	g++ main.cpp ArrayStack.o archivo.o -o main

main.o:	main.cpp ArrayStack.h Stack.h archivo.h 
	g++ -c main.cpp

ArrayStack.o:	ArrayStack.cpp ArrayStack.h
	g++ -c ArrayStack.cpp

archivo.o:	archivo.cpp archivo.h
	g++ -c archivo.cpp
clean:
	rm  *.o main