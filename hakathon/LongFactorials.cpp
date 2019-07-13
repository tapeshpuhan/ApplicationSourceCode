#include <bits/stdc++.h>

using namespace std;

void print(const vector<int> v)
{
    for(auto at : v)
   {
       cout<<at<<" ";
   }
   cout<<endl;  
}

vector<int> AddMerge(const vector<int>& a, const vector<int>& b)
{
    size_t l_a = a.size();
    size_t l_b = b.size();
    vector<int> out;
    int reminder = 0;
    
    size_t l_max = max(l_a, l_b);
    
    for(size_t index = 0; index < l_max; ++index)
    {
          if(index < l_a && index < l_b)
          {
              auto res = a[index] + b [index];
              res = res + reminder;
              reminder = (res/10);
              out.push_back(res%10);
          }  
          else if(index < l_a)
          {
              auto res = a[index] + reminder;
              reminder = (res/10);
              out.push_back(res%10);
          }
          else
          {
              auto res = b[index] + reminder;
              reminder = (res/10);
              out.push_back(res%10); 
          }                  
    }
    if(reminder)
    out.push_back(reminder); 
    return out;
}

vector<int> MultiplyList(const vector<int>& a, int value, int index)
{
    vector<int> out;
    int reminder = 0;
    
    if(index)
    {
        for(int i = 0; i < index;++i)
        {
            out.push_back(0);
        }
    }
    for(auto& at : a)
    {
        int res = at * value;
        res = res + reminder;
        reminder = (res/10);
        out.push_back(res%10);        
    }
    if(reminder)
    out.push_back(reminder); 
    return out;
}


string Multiplay(string a, string b)
{
   vector<int> as;
   vector<int> bs;
   vector<int> out;
   string result;
   
   for_each(a.rbegin(),a.rend(),[&](const int c){ as.push_back(c -'0');});
   for_each(b.rbegin(),b.rend(),[&](const int c){ bs.push_back(c -'0');});
      
   for(int index = 0; index < bs.size(); ++index)
   {
       auto res = MultiplyList(as,bs[index],index);
       if(!out.empty())
       {
           out = AddMerge(out, res);
       }
       else
       {
           out = res;
       }
   }
   for_each(out.rbegin(),out.rend(),[&](const int c){ result.push_back(c+'0');});
   return result;
}

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    string result{"1"};
    int count = 2;
    while(n > 1)
    {
        result = Multiplay(result,to_string(count));
        n--;
        count++;
    }
    cout<<result<<endl;    
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);
    
    //auto res = Multiplay("87178291200","15");
    

    //cout<<res<<endl;

    return 0;
}
