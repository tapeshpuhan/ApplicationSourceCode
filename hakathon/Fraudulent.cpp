#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int getMedianMap(const vector<int>& expenditure)
{
    multiset<int> input_s{expenditure.begin(),expenditure.end()};

    int n = input_s.size();
    
    cout<<n<<endl;
    
    /*if((n%2) == 0)
    {        
                int x = n/2;
        return (input[x] + input[x+1])/2;
    }
    return input[n/2];*/
}


int getMedian(const vector<int>& expenditure)
{
    vector<int> input{expenditure.begin(),expenditure.end()};
   // std::sort(input.begin(),input.end());
   auto max = max_element(begin(input), end(input));
   const size_t num = *max;
   vector<int> out(num+1);
   
   for(auto& at : input)
   {
       out[at]++;
   }
   input.clear();
   for(int index = 0; index < out.size(); ++index)
   {
       if(out[index])
       {
           for(int i = 0; i < out[index];++i)
           {
              input.push_back(index); 
           }
       }
   }

    int n = input.size();
    
    if((n%2) == 0)
    {        
                int x = n/2;
        return (input[x] + input[x+1])/2;
    }
    return input[n/2];
}

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {

int n = expenditure.size();
int count = 0;

for(int index = 0 ; (index + d) < (n-1);++index)
{
    int mid = getMedianMap({expenditure.begin()+index,expenditure.begin()+(index+d)});
    if(expenditure[d] >= (mid*2))
    {
        count++;
    }
}
return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    cout << result << "\n";

    fout.close();
    
    //cout<<getMedian({2,3,6,8,4})<<endl;

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
