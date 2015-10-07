all: string_in_c cpp_base_samples c_base_samples \
     singleton C_File_Op Cpp_File_Op test_class_size \
     test_vector
     
clean:
	rm string_in_c cpp_base_samples c_base_samples \
    singleton C_File_Op Cpp_File_Op test_class_size \
    test_vector
    
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
    
test_class_size: ClassicSamples/test_class_size.cpp
	g++ -o test_class_size ClassicSamples/test_class_size.cpp
    
test_vector: STL/test_vector.cpp
	g++ -o test_vector STL/test_vector.cpp