#include <iostream>
#include <unordered_map>
#include <functional>
#include <algorithm>

class Emp
{
    public:
    explicit Emp(int emp_no, const std::string& name):emp_no_{emp_no},name_{name}
    {
    }
    bool operator <(const Emp& emp) const
    {
        return emp_no_ < emp.emp_no_;
    }
    
    bool operator ==(const Emp& emp) const
    {
        return emp_no_ == emp.emp_no_;
    }
    
    bool operator !=(const Emp& emp) const
    {
        return emp_no_ != emp.emp_no_;
    }
    int GetEmpId()const
    {
        return emp_no_;
    }
    std::string GetEmpName()const
    {
        return name_;
    }
    private:
    int emp_no_;
    std::string name_;
};

struct EmpHash
{
    size_t operator()(const Emp& emp)const 
    {
        return std::hash<int>()(emp.GetEmpId()) + std::hash<std::string>()(emp.GetEmpName());
    }
};

int main()
{
    std::unordered_map<Emp,std::string,EmpHash> EmpInfo;
    Emp o1(1,"Vari");
    Emp o2(2,"Number");
    
    EmpInfo[o1] = "Ram";
    EmpInfo[o2] = "Sam";
    
    for(auto& at : EmpInfo)
    {
        std::cout<<"Emp Id : "<<at.first.GetEmpId()<<" Emp Name: "<<at.second<<std::endl; 
    }
    
    return 0;
}
