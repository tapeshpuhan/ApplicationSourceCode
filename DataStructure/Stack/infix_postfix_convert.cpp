#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>

const std::map<char,std::int32_t> operator_precidency_table{{'+',0},{'-',0},{'*',1},{'/',1}};

bool IsOperator(const char ch)
{
    return operator_precidency_table.find(ch) != cend(operator_precidency_table);
}
bool IsLowerOrEqualPrecidence(const char source, const char dest)
{
    bool result = 0;
    auto source_index = operator_precidency_table.find(source);
    auto dest_index = operator_precidency_table.find(dest);
    
    if((source_index != cend(operator_precidency_table)) && ( dest_index != cend(operator_precidency_table)))   
    {
        //std::cout<<(source_index->second) <<" : "<<(dest_index->second)<<std::endl;
        result = ((source_index->second) <=  (dest_index->second));
    }
    return result;
}

std::string Convert(const std::string& input)
{
    std::stack<char> operator_stack_;
    std::string out_result;
    
    for(auto& each_char_from_input : input)
    {
        if(IsOperator(each_char_from_input))
        {
            if(operator_stack_.empty())
            {
                operator_stack_.push(each_char_from_input);
            }
            else
            {
                auto dest_operator = operator_stack_.top();
                
                while(IsLowerOrEqualPrecidence( each_char_from_input, dest_operator)) 
                {
                    out_result.push_back(dest_operator);
                    operator_stack_.pop();
                    if(!operator_stack_.empty())
                    {
                        dest_operator = operator_stack_.top();
                    }
                    else
                    {
                        break;
                    }
                }
                operator_stack_.push(each_char_from_input);
            }
        }
        else
        {
            out_result.push_back(each_char_from_input);
        }
    }
    while(!operator_stack_.empty())
    {
        out_result.push_back(operator_stack_.top());
        operator_stack_.pop();
    }
    return out_result;
}

int main()
{
    std::cout<<Convert("a+b*c-d/e")<<std::endl;
    //std::cout<<IsLowerOrEqualPrecidence('-','*')<<std::endl;
    return 0;
} 
