all: string_in_c cpp_base_samples c_base_samples \
     singleton C_File_Op Cpp_File_Op
     
clean:
	rm string_in_c cpp_base_samples c_base_samples \
    singleton C_File_Op Cpp_File_Op
    
string_in_c: string_in_c.c
	gcc -o string_in_c string_in_c.c
    
cpp_base_samples: base_samples.cpp
	g++ -o cpp_base_samples base_samples.cpp
    
c_base_samples: base_samples.c
	gcc -o c_base_samples base_samples.c

singleton: ClassicSamples/Singleton.cpp
	g++ -o singleton ClassicSamples/Singleton.cpp
    
C_File_Op: ClassicSamples/C_File_Op.c
	g++ -o C_File_Op ClassicSamples/C_File_Op.c

Cpp_File_Op: ClassicSamples/Cpp_File_Op.cpp
	g++ -o Cpp_File_Op ClassicSamples/Cpp_File_Op.cpp