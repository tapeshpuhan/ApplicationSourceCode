#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    vector<int> rank;
    rank.reserve(alice.size());
    
    scores.erase(std::unique(begin(scores),end(scores)),scores.end());
    
    for(auto& at : alice)
    {
      auto find_index = std::find_if(cbegin(scores),cend(scores),[&](const auto& num)
      {
          return num <= at;
        });
        if(cend(scores) != find_index)
        {
            rank.push_back(std::distance(cbegin(scores),find_index)+1);
        }
        else
        {
            rank.push_back(scores.size()+1);
        }   
    }
    return rank;    
}

vector<int> climbingLeaderboard_old(vector<int> scores, vector<int> alice) {
    vector<int> rank;
    rank.reserve(alice.size());
    int prev_rank =0;

    size_t j=0;
    
    std::reverse(alice.begin(),alice.end());
    
    for(int index = 0; index < alice.size(); )
    {
      if(j < scores.size())
      {
          if(scores[j] == alice[index])
          {
              rank.push_back(prev_rank + 1);
              index++;              
          }
          else if(scores[j] < alice[index])
          {
              rank.push_back(prev_rank + 1);
              index++;
          }
          else
          {              
              if(j !=0 && scores[j-1] == scores[j])
              {
                
              }
              else 
              {
                  prev_rank++;
              }
              j++;
          }
      }
      else
      {
         rank.push_back(prev_rank+1);
            
            index++;
      }
      
    }
    
    std::reverse(rank.begin(),rank.end());
    return rank;    
}

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard_map(vector<int> scores, vector<int> alice) {
    vector<int> rank;
    int count =1;
    int prev = -1;
    //std::unordered_map<int , int> _score_map;
    std::map<int , int> _score_map;
    
    for(auto& at : scores)
    {
        if(prev != at)
        {
            _score_map.insert({at,count++});
            prev = at;
        }
    }
        
    rank.reserve(alice.size());
    for(auto& at : alice)
    {
        auto res = std::find_if(crbegin(_score_map),crend(_score_map),[&](const auto& param)
        {
            return param.first <= at;
            });
        if(res!= crend(_score_map))
        {
            rank.push_back(res->second);
        }
        else{
            rank.push_back(count);
        }
    }
    
    return rank;    
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard_old(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    fout.close();

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
