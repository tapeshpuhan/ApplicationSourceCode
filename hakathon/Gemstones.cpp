#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {
    int number = 0;
if(arr.size())
{
    std::sort(arr.begin(),arr.end(),[](auto a, auto b){return a.length()<b.length();});
    set<char> first {arr[0].begin(),arr[0].end()};
    
    for(auto& at : first)
    {
        bool get_value = false;
        for(int index = 1; index < arr.size(); ++index)
        {
            auto get_index = std::find(arr[index].begin(),arr[index].end(),at);
            if(get_index == arr[index].end())
            {
                get_value = false;
                break;
            }
            get_value = true;            
        }
        if(true == get_value)
        {
            number++;
        }
    }
    
}
return number;
}

int main()
{


    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    cout << result << "\n";


    return 0;
}
