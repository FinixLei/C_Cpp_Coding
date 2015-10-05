all: string_in_c cpp_base_samples c_base_samples \
     singleton
     
clean:
	rm string_in_c cpp_base_samples c_base_samples \
    singleton
    
string_in_c: string_in_c.c
	gcc -o string_in_c string_in_c.c
    
cpp_base_samples: base_samples.cpp
	g++ -o cpp_base_samples base_samples.cpp
    
c_base_samples: base_samples.c
	gcc -o c_base_samples base_samples.c

singleton: ClassicSamples/Singleton.cpp
	g++ -o singleton ClassicSamples/Singleton.cpp
