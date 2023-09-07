main: main.o
	g++ main.cpp -o main

main.o: main.cpp
	g++ -c main.cpp

run: main
	./main

clean:
	rm -f *.o
	rm main
	rm photo20.raw
	rm photo100.raw
