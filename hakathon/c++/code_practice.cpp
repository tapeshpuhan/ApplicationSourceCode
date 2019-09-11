#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the plusMinus function below.
void plusMinus(vector<int> arr) {
  int size = arr.size();


  int pos_{0};
  int neg{0};
  int zer{0};

  for(auto a: arr)
  {
      if(a > 0)
      {
          pos_++;
      }
      else if(a == 0)
      {
          zer++;
      }
      else  {
      neg++;
      }
  }
cout<<pos_<<" "<<size<<endl;
cout<<zer<<" "<<size<<endl;
cout<<neg<<" "<<size<<endl;
  double positive = static_cast<double>(pos_)/static_cast<double>(size);
  double negative = neg/size;
  double zero = zer/size;
  
  std::cout<<fixed<<std::setprecision(5)<<positive<<std::endl;
  std::cout<<negative<<std::endl;
  std::cout<<zero<<std::endl;
  
  double pi = 0.5, npi = -0.5; 
    cout << fixed << setprecision(0) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(5) << pi <<" "<<npi<<endl;

}

int main()
{
    /*
    int n;
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
*/
    plusMinus({-4, 3, -9, 0, 4, 1});

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
