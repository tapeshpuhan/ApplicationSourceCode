#include <iostream>
#include <map>

class Emp
{
    public:
    explicit Emp(int emp_no):emp_no_{emp_no}{
    }
    bool operator <(const Emp& emp) const
    {
        return emp_no_ < emp.emp_no_;
    }
    int GetEmpId()const
    {
        return emp_no_;
    }
    private:
    int emp_no_;
};

int main()
{
    std::map<Emp,std::string> EmpInfo;
    Emp o1(1);
    Emp o2(2);
    
    EmpInfo[o1] = "Ram";
    EmpInfo[o2] = "Sam";
    
    for(auto& at : EmpInfo)
    {
        std::cout<<"Emp Id : "<<at.first.GetEmpId()<<" Emp Name: "<<at.second<<std::endl; 
    }
    
    return 0;
}
