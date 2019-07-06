#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Person
{
    virtual void getdata()=0;
    virtual void putdata()=0;
    virtual ~Person()=default;
    
};

class Professor : public Person
{
  public:
    void getdata()
    {
        cin>>name>>age>>publication;
        a = Professor::GetId();
    }
    void putdata()
    {
        
        cout<<name<<" "<<age<<" "<<publication<<" "<<a<<endl;
    }
    static int GetId(){id= id+1; return id;}
    private:
    string name;
    int age;
    int publication;
    int a;  
    static int id;  
};
int Professor::id=0;
class Student : public Person
{
  public:
    void getdata()
    {
       cin>>name>>age ;
       for(int i = 0; i < 6; ++i)
       {
            cin>>mark[i];
            
       }
       a = Student::GetId();
    }
    void putdata()
    {        
        cout<<name<<" "<<age<<" ";
        int sum = 0;
       for(int i = 0; i < 6; ++i)
       {
            sum += mark[i];            
       }
       cout<<sum<<" "<<a<<endl;
    }
    static int GetId(){id= id+1; return id;}
    private:
    
    string name;
    int age;
    int mark[6];
    static int id;
    int a; 
};
int Student::id=0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
