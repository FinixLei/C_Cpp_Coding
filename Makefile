all: string_in_c base_samples_cpp

string_in_c:
	gcc -o string_in_c string_in_c.c
    
base_samples_cpp:
	g++ -o base_samples_cpp base_samples.cpp
    