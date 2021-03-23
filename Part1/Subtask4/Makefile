
all: runall main1 main2 main3

# Subtask 1:
main1: main1_1.o hello_ariel.o
	gcc -Wall -g -o main1 main1_1.o hello_ariel.o && ./main1

main1_1.o: main1_1.c hello_ariel.h
	gcc -c -Wall -g main1_1.c 

hello_ariel.o: hello_ariel.c hello_ariel.h
	gcc -c -g -Wall hello_ariel.c 


#Subtask 2:
main2: main1_2.o hello_ariel.o
	gcc -Wall -g -o main2 main1_2.o hello_ariel.o

main1_2.o: main1_2.c hello_ariel.h
	gcc -c -Wall -g main1_2.c 

lib_ariel.so: hello_ariel.o
	gcc -Wall -g -fPIC -c hello_ariel.c

# hello_ariel.o: hello_ariel.c hello_ariel.h
# 	gcc -c -g -Wall hello_ariel.c 



# Subtask 3:

# First Version LD_LIB... Not working
main3: hello_ariel.so #hello_ariel.so is needed to run main
	gcc main1_3.c -L. lib_hello_ariel.so -o main3

hello_ariel.so: hello_ariel.c	# hello_ariel.c/.h are needed to compile the lib
	gcc -o lib_hello_ariel.so -shared -fPIC hello_ariel.c

runall: main1 main2 main3
	./main1 && ./main2 && ./main3
clean:
	rm -f main1 main2 main3 *.o *.so