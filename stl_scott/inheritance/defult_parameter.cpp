#include <iostream>
#include <memory>

enum class  JobType
{
    Contract,
    Permanent
};

class Employe
{
    public:
    void SetJob(const JobType job=JobType::Permanent)
    {
       SetJobType(job); 
    }
    private:
    virtual void SetJobType(const JobType job)=0;
};

class MunichEmpolye : public Employe
{
    private:
    virtual void SetJobType(const JobType job)override
    {
        std::cout<<"MunichEmpolye "<<static_cast<int32_t>(job)<<std::endl;
    }
};

int main()
{
    std::unique_ptr<Employe> emp = std::make_unique<MunichEmpolye>();
    emp->SetJob();
    return 0;
}
