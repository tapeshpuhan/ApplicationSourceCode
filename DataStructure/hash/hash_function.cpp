#include <iostream>
#include <functional>
#include <unordered_set>
#include <string>

class Empoly
{
    public:
    
    Empoly():emp_number{0},emp_name{""}
    {
    }
    Empoly(const int emp, const std::string& name):emp_number{emp},emp_name{name}
    {
    }
    void SetEmployData(const std::string& name, const int emp)
    {
        emp_number = emp;
        emp_name = name;
    }
    
    size_t GetHashValue() const noexcept
    {
        return std::hash<int>()(emp_number) + std::hash<std::string>()(emp_name);
    }
    
    bool operator == (const Empoly& emp) const
    {
        return emp_number == emp.emp_number;
    }
    
    void display()const 
    {
        std::cout<<"emp_n "<<emp_number<<" name "<<emp_name<<std::endl;
    }
    
    private:
    int emp_number;
    std::string emp_name;
};



template<typename HASHTYPE>
class MyHash
{
    public:
    
    size_t operator()(const HASHTYPE& hash_type) const noexcept
    {
        return hash_type.GetHashValue();
    }
};

template<typename COMPTYPE>
class MyComp
{
    public:
    
    bool operator ()(const COMPTYPE& comp_one,const COMPTYPE& comp_two) const noexcept
    {
        return comp_one == comp_two;
    }
};

int main()
{
    
    
    Empoly e1{100,"rama"};
    Empoly e2{200,"rama"};
    Empoly e3{300,"rama"};
    
    std::unordered_multiset<Empoly,MyHash<Empoly>,MyComp<Empoly>> store_emp_data= {e1, e2,e3};
    

    store_emp_data.insert(e1);
    store_emp_data.insert(e2);
    store_emp_data.insert(e3);
    for(auto& at : store_emp_data)
    {
        at.display();
    }
    
    return 0;
}
