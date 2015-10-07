GPP := g++ -std=c++11
CC := gcc

all: string_in_c cpp_base_samples c_base_samples \
     singleton C_File_Op Cpp_File_Op test_class_size test_copy_constructor \
     ReverseLinkedList ClassicListAll \
     test_vector
     
clean:
	rm string_in_c cpp_base_samples c_base_samples \
    singleton C_File_Op Cpp_File_Op test_class_size test_copy_constructor \
    ReverseLinkedList ClassicListAll \
    test_vector
    
string_in_c: string_in_c.c
	${CC} -o string_in_c string_in_c.c
    
cpp_base_samples: base_samples.cpp
	${GPP} -o cpp_base_samples base_samples.cpp
    
c_base_samples: base_samples.c
	${CC} -o c_base_samples base_samples.c

singleton: ClassicSamples/Singleton.cpp
	${GPP} -o singleton ClassicSamples/Singleton.cpp
    
C_File_Op: ClassicSamples/C_File_Op.c
	${CC} -o C_File_Op ClassicSamples/C_File_Op.c

Cpp_File_Op: ClassicSamples/Cpp_File_Op.cpp
	${GPP} -o Cpp_File_Op ClassicSamples/Cpp_File_Op.cpp
    
test_class_size: ClassicSamples/test_class_size.cpp
	${GPP} -o test_class_size ClassicSamples/test_class_size.cpp
    
test_copy_constructor: ClassicSamples/test_copy_constructor.cpp
	${GPP} -o test_copy_constructor ClassicSamples/test_copy_constructor.cpp
    
ReverseLinkedList: Algorithm/ReverseLinkedList.cpp
	${GPP} -o ReverseLinkedList Algorithm/ReverseLinkedList.cpp
    
ClassicListAll: Algorithm/ClassicListAll.cpp
	${GPP} -o ClassicListAll Algorithm/ClassicListAll.cpp
    
test_vector: STL/test_vector.cpp
	${GPP} -o test_vector STL/test_vector.cpp
