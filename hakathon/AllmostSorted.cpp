#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool AllSorted(const vector<int>& arr,size_t index)
{    
    for(int i = index; i < arr.size()-1; ++i)
    {
        if(arr[i+1] < arr[i] )
        {
            return false;
        }
    }
    return true;
}

std::pair<bool,size_t> FindReverseIndex(const vector<int>& arr, const size_t index , int& out_index)
{
 std::pair<bool,size_t> ret;
 bool get_first_reverse = true;
 auto n = arr[index];
  size_t valid_index =  index;
 
 for(int j = index; j < arr.size()-1; ++j)
 {
     if(arr[j+1] < n)
     {
         if(arr[j+1] > arr[j])
         {
             get_first_reverse =false;
             break;
         }
         else
         {
             valid_index = j+1;
         }
     }
     else
     {
         break;
     }
 }
 out_index = valid_index+1;
 return make_pair(get_first_reverse,valid_index);
}

std::pair<bool,size_t> FindSwapIndex(const vector<int>& arr, const size_t i, int& out_index)
{
  bool found = false;
  auto X = arr[i];
  auto Y = arr[i+1];
  auto j = i+2;
  auto valid_index = i+1;
  
  if(j < arr.size())
  {
      auto min = X;
      auto max = arr[j];
      while(j < arr.size())
      {
          if(arr[j] > Y)
          {
              break;
          }
          if(arr[j] == min || arr[j] == max)
          {
              valid_index = j;
              found = true; 
          }
          else if(arr[j] > min && arr[j] < max)
          {
              valid_index = j;
              found = true;
              break;
          }
          else
          {
              found = false; 
          }
          j++;
      }
  }
  else
  {
      found = true;
  }  
  out_index = valid_index+1;
  return make_pair(found, valid_index);
}

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {

    size_t length = arr.size();
    bool reverse = false;
    bool swap = false;
    size_t index_start = 0;
    size_t index_end = 0;
    int previous = 0;
     
    for(int i = 0; i < length-1;++i)
    {
        if(i == 0)
        {
            if(arr[i] > arr[i+1])
            {
                index_start = i;
                index_end = i+1;
                swap = true;
                if(index_end+1 < arr.size())
                {
                    if(arr[index_end+1] < arr[index_start])
                    {
                        swap = false;
                    }
                    else
                    swap = AllSorted(arr, index_end+1);
                }
                break;
            }            
        }
        else if(arr[i] > arr[i+1])
        {
           
            int out_ind;
            auto ret = FindSwapIndex(arr,i,out_ind);
            if(ret.first == true)
            {
             index_start = i+1;
             index_end  = ret.second+1;
             swap = AllSorted(arr,out_ind);
             
            }
            else
            {                
                auto ret_1 = FindReverseIndex(arr,i,out_ind);                    
                    if(ret_1.first == true)
                    {
                        if(previous <= arr[ret_1.second])
                        {
                            index_start = i;
                            index_end  = ret_1.second;
                            reverse = AllSorted(arr,out_ind);;
                        }
                    }
             
            }
            break;
        }
        previous = arr[i];
    }
    if(swap)
    {
        std::cout<<"yes"<<std::endl;
        std::cout<<"swap "<<index_start+1<<" "<<index_end+1<<std::endl;
    }
    else if(reverse)
    {
              std::cout<<"yes"<<std::endl;
        std::cout<<"reverse "<<index_start+1<<" "<<index_end+1<<std::endl;  
    }
    else
    {
        std::cout<<"no"<<std::endl;
    }

}

int main()
{
    /*int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);*/
    
    almostSorted({4,2});
    almostSorted({3,1,2});
    almostSorted({1 ,5, 4, 3, 2, 6});
    almostSorted({43, 65, 1, 98, 99, 101});
    
    //cout <<AllSorted({1,3,2,5,7,9,12},7)<<endl;
    

    int out;
    //auto at = FindReverseIndex({1,5,4,1,4,7,8},1,out);
   // auto at = FindReverseIndex({5,4,3},0,out);
       //auto at = FindReverseIndex({1 ,5, 4, 3, 2, 6},1,out);
       auto at = FindReverseIndex({43, 65,2, 1, 98, 99, 101},1,out);
    //cout<<at.first<<" : "<<at.second<<" : "<<out<<endl;
    
    //int out;
    //auto at = FindSwapIndex({4,1},0,out);    
    //auto at = FindSwapIndex({1 ,5, 4, 3, 2, 6},1,out);    
    //cout<<at.first<<" : "<<at.second<<" : "<<out<<endl;
    
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
