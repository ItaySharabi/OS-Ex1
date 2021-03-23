
main2: main1_2.o hello_ariel.o
	gcc -Wall -g -o main2 main1_2.o hello_ariel.o

main1_2.o: main1_2.c hello_ariel.h
	gcc -c -Wall -g main1_2.c 

lib_ariel.so: hello_ariel.o
	gcc -Wall -g -fPIC -c hello_ariel.c

hello_ariel.o: hello_ariel.c hello_ariel.h
	gcc -c -g -Wall hello_ariel.c 

clean:
	rm -f main2 *.o

# # First Version LD_LIB... Not working
# main: hello_ariel.so #hello_ariel.so is needed to run main
# 	gcc main1_1.c -L. libHello_ariel.so -o main && ./main

# hello_ariel.so: hello_ariel.c	# hello_ariel.c/.h are needed to compile the lib
# 	gcc -o libHello_ariel.so -shared -fPIC hello_ariel.c

# clean:
# 	rm -f *.o *.so main



