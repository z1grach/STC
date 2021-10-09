#include <iostream>


using namespace std;

typedef unsigned int size_t;

template<typename T>
class Vector
{
private:
    size_t m_size;
    size_t m_capacity;
    T* m_data;

public:
    Vector() : m_size(0), m_capacity(0), m_data(nullptr)
    { }

    Vector (size_t length, T value = 0)
    {
        if (length < 0)
            exit(0);

        if (length > 0) {
            m_capacity = length;
            m_size = length;
            m_data = new T[length];

            for (int i = 0; i < m_capacity; ++i) {
                m_data[i] = value;
            }
        }
        else {
            m_capacity = length;
            m_size = length;
            m_data = nullptr;
        }
    }


    ~Vector()
    {
        delete[] m_data;
    }


    void clear()
    {
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = 0;
        }
        m_size = 0;
    }


    size_t size() const
    { 
        return m_size;
    }


    size_t capacity() const
    {
        return m_capacity;
    }
    

    void resize(size_t newLength)
    {
    
        if (newLength == m_size)
            return;
      
        if (newLength <= 0)
        {
            clear();
            return;
        }

        if (m_capacity >= newLength) {
            if (m_size == newLength)
                return;

            for (size_t i = newLength; i < m_capacity; ++i) {
                m_data[i] = 0;
            }
            m_size = newLength;

            return;
        }
     
        
        T* data = new T[newLength];
        for (size_t index = 0; index < newLength; ++index)
            data[index] = m_data[index];

        for (size_t i = m_capacity; i < newLength; ++i) {
            data[i] = 0;
        }

        delete[] m_data;

        m_data = data;
        m_size = newLength;
        m_capacity = newLength;

    }


    void push_back(const T value)
    {
        if (m_data == nullptr) {
            m_data = new T[1];
            *m_data = value;
            m_size = 1;
            m_capacity = 1;

            return;
        }




        if (m_size < m_capacity) {
            m_data[m_size] = value;
            ++m_size;
            return;
        }

        else {

            ++m_capacity;

            T* data = new T[m_capacity];
            for (size_t index = 0; index < m_capacity - 1; ++index)
                data[index] = m_data[index];

            data[m_capacity - 1] = value;

            delete[] m_data;

            m_data = data;
            m_size = m_capacity;

        }

    }


    T& pop_back()
    {
        if (m_size <= 0)
            exit(0);

        T value = m_data[m_size - 1];
        m_data[m_size - 1] = 0;
        --m_size;

        return value;
    }


    T& operator [](size_t index)
    {
        if (index >= 0 && index < m_size)
            return m_data[index];

        else exit(0);
    }


    void print()
    {
        if (m_size <= 0)
            exit(0);

        for (int i = 0; i < m_size; ++i) {
            cout << m_data[i] << ' ';
        }cout << endl;
    }
   
};


int main()
{
    Vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    

    cout << v.pop_back() << endl;
    cout << v.pop_back() << endl;

    v.print();
    cout << v.capacity() << ' ' << v.size() << endl;

    return 0;
}
