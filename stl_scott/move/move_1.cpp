#include <iostream>
#include <type_traits>

struct Test
{
    Test()
    {
        std::cout<<"Constructor called"<<std::endl;
    }
    Test(const Test&)
    {
        std::cout<<"Copy Constructor"<<std::endl;
    }
    Test(Test&&)
    {
        std::cout<<"Move Constructor"<<std::endl;
    }
    Test operator=(const Test& a)
    {
        std::cout<<"copy assisnment"<<std::endl;
        return a;
    }
    Test operator=(Test&& a)
    {
        std::cout<<"move assisnment"<<std::endl;
        return a;
    }
};

template<typename T>
typename std::remove_reference<T>::type&&
MOVE(T&& value)
{
        using type_t = typename std::remove_reference<T>::type;
        return static_cast<type_t>(value);
}

void fun(int&& a)
{
    std::cout<<a<<std::endl;
    a++;
}

template<class T1, class T2>
void print_is_same() {
  std::cout << std::is_same<T1, T2>() << '\n';
}

int main()
{
    const Test a;
    Test b(std::move(a));
    
    fun(100);
     int x =200;
    fun(std::move(x));
    
    const int&& pq =x;
    
       print_is_same<int, int &&>();
       print_is_same<int, std::remove_reference<int &&>::type>();
    
}
