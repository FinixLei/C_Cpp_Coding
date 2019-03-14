class Singleton
{
public:
    static Singleton * get_instance();
    
    
private:
    Singleton() {}
    ~Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton operator= (const Singleton &) = delete;
    
private:
    static Singleton * pointer; 
};

Singleton * Singleton::pointer = 0;

Singleton * Singleton::get_instance()
{
    if (Singleton::pointer == 0) {
        Singleton::pointer = new Singleton();
    }
    return Singleton::pointer;
}

