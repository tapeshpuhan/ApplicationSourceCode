#include <vector>
#include <iostream>

template<typename T>
class Stack
{
    public:
    Stack()=default;
    explicit Stack(const size_t size):max_size_{size},stack_(size){}
    void Push(const T& value)
    {
        if(Index < max_size_)
        {
            Index++;
            stack_.at(Index-1) = value;            
        }
    }
    void Pop()
    {
        if(!IsEmpty())
            Index--;   
    }
    T Top()
    {
        return stack_.at(Index-1);            
    }
    bool IsEmpty()
    {
        return Index == 0;
    }
    size_t Size()
    {
        return Index-1;
    }
    void print()
    {
        for(auto& at : stack_)
        {
            std::cout<<at<<std::endl;
        }
    }
    private:
    std::vector<T> stack_;
    size_t max_size_;
    size_t Index{0};
};

int main()
{
    Stack<int> st(5);
    
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Pop();
    st.Push(20);
    
    //st.print();
    while(!st.IsEmpty())
    {
        const auto& top = st.Top();
        std::cout<<top<<std::endl;
        st.Pop();
    }
    return 0;
}
