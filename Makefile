all: string_in_c.exe base_samples_cpp.exe

string_in_c.exe:
	gcc -o string_in_c string_in_c.c
    
base_samples_cpp.exe:
	g++ -o base_samples_cpp base_samples.cpp
    