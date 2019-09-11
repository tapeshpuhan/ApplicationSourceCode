#include <iostream>
#include <memory>

class Employe
{
    public:
    int GetInfo()
    {
        return GetEmpId();
    }
    private:
    virtual int GetEmpId()
    {
        return id_;
    }
    int id_{100};
};

class ContractEmploye : public Employe
{
    public:
    /*int GetEmpId() override
    {
        return id_;
    }*/
    private:
    int id_{200};
};

int main()
{
    std::unique_ptr<Employe> emp = std::make_unique<ContractEmploye>();
    
    std::cout<<emp->GetInfo()<<std::endl;
    
    return 0;
}
