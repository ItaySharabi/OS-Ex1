# The call to export LD_LIBRARY_PATH=. [ . == current directory]
main: hello_ariel.so #hello_ariel.so is needed to run main
	gcc main1_1.c -L. libHello_ariel.so -o main

hello_ariel.so: hello_ariel.c	# hello_ariel.c/.h are needed to compile the lib
	gcc -o libHello_ariel.so -shared -fPIC hello_ariel.c

# libs: 
# 	export LD_LIBRARY_PATH=. VERY IMPORTANT FOR LOADING THE LIBRARY INTO THE PROGRAM!!!
clean:
	rm -f *.o *.so main