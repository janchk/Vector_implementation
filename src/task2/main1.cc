template<typename T>
class Vector
{
    std::size_t     capacity;
    std::size_t     length;
    T*              buffer;
    Vector(int capacity)
        : capacity(capacity = 100)
        , length(0)
        , buffer(static_cast<T*>(::operator new(sizeof(T) * capacity)))
    {}
    ~Vector()
    {
        for(int loop = 0; loop < length; ++loop)
        {
            buffer[length - 1 - loop].~T();
        }
        ::operator delete(buffer);
    }
    Vector(Vector const& copy)
        : capacity(copy.length)
        , length(0)
        , buffer(static_cast<T*>(::operator new(sizeof(T) * capacity)))
    {
        for(int loop = 0; loop < copy.length; ++loop)
        {
            push_back(copy.buffer[loop]);
        }
    }
    Vector& operator=(Vector const& copy)
    {
        return *this;
    }
    void push_back(T const& value)
    {
        new (buffer + length) T(value);
        ++length;

    }
    void pop_back()
    {
        --length;
        buffer[length].~T();
    }
};
