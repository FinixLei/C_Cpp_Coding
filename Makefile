GPP := g++ -std=c++11
CC := gcc

all: string_in_c cpp_base_samples c_base_samples \
     singleton C_File_Op Cpp_File_Op test_class_size test_copy_constructor test_strcpy \
     test_String test_autoptr test_Matrix \
     ReverseLinkedList ClassicListAll CommonListAll\
     test_vector template_specialize
     
clean:
	rm -f string_in_c cpp_base_samples c_base_samples \
    singleton C_File_Op Cpp_File_Op test_class_size test_copy_constructor test_strcpy \
    test_String String.o test_autoptr ClassicSamples/Matrix/Matrix.o test_Matrix \
    ReverseLinkedList ClassicListAll CommonListAll \
    test_vector template_specialize

# Root 
string_in_c: string_in_c.c
	${CC} -o string_in_c string_in_c.c
    
cpp_base_samples: base_samples.cpp
	${GPP} -o cpp_base_samples base_samples.cpp
    
c_base_samples: base_samples.c
	${CC} -o c_base_samples base_samples.c


# ClassicSamples folder
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
    
test_strcpy: ClassicSamples/test_strcpy.cpp
	${GPP} -o test_strcpy ClassicSamples/test_strcpy.cpp
    
String.o: ClassicSamples/String/String.h ClassicSamples/String/String.cpp
	${GPP} -c ClassicSamples/String/String.cpp
    
test_String: ClassicSamples/String/test_String.cpp String.o
	${GPP} -o test_String ClassicSamples/String/test_String.cpp String.o
    
test_autoptr: ClassicSamples/Autoptr/test_autoptr.cpp ClassicSamples/Autoptr/autoptr.h
	${GPP} -o test_autoptr ClassicSamples/Autoptr/test_autoptr.cpp
    
Matrix.o: ClassicSamples/Matrix/Matrix.h ClassicSamples/Matrix/Matrix.cpp
	${GPP} -c ClassicSamples/Matrix/Matrix.cpp -o ClassicSamples/Matrix/Matrix.o
    
test_Matrix: Matrix.o ClassicSamples/Matrix/test_Matrix.cpp
	${GPP} -o test_Matrix ClassicSamples/Matrix/Matrix.o ClassicSamples/Matrix/test_Matrix.cpp
    
# Algorithm folder
ReverseLinkedList: Algorithm/ReverseLinkedList.cpp
	${GPP} -o ReverseLinkedList Algorithm/ReverseLinkedList.cpp
    
ClassicListAll: Algorithm/ClassicListAll.cpp
	${GPP} -o ClassicListAll Algorithm/ClassicListAll.cpp
    
CommonListAll: Algorithm/CommonListAll.cpp
	${GPP} -o CommonListAll Algorithm/CommonListAll.cpp 

# STL folder
test_vector: STL/test_vector.cpp
	${GPP} -o test_vector STL/test_vector.cpp
    
template_specialize: STL/template_specialize.cpp
	${GPP} -o template_specialize STL/template_specialize.cpp
    