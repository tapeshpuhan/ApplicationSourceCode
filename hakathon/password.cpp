#include <bits/stdc++.h>

using namespace std;

bool ifFound(int numb, string numbers)
{
    bool found = 0;
         
    
    if(numbers.find(numb) != std::string::npos)
    {
        found = true;
    }
    return found;
}

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int count_strong = 0;
    bool numb_found = false;
    bool uper_found = false;
    bool lower_found = false;
    bool specal_found = false;
    int length = password.length();
    int result = 0;
    
    std::all_of(begin(password),end(password), [&](int ch)
        {
            
            if(!numb_found && ifFound(ch,"0123456789"))
            {
                numb_found = true;
                count_strong++;
            }
            if(!uper_found && ifFound(ch,"ABCDEFGHIJKLMNOPQRSTUVWXYZ"))
            {
                uper_found = true;
                count_strong++;
            }
            if(!lower_found && ifFound(ch,"abcdefghijklmnopqrstuvwxyz"))
            {
                lower_found = true;
                count_strong++;
            }
            if(!specal_found && ifFound(ch,"!@#$%^&*()-+"))
            {
                specal_found = true;
                count_strong++;
            }
            if(count_strong == 4)
            {
                return false;
            }
            return true;
        }
            );
            if(count_strong < 4)
            {
                if(length >= 6)
                {
                    result = 4-count_strong;
                }
                else 
                {
                    result = std::max(6-length, 4 - count_strong);
                }
            }
            else if( length< 6)
            {
                result = 6 - length ;
            }
            
    return result;
}

int main()
{


    int answer = minimumNumber(11, "#HackerRank");

    cout << answer << "\n";


    return 0;
}
