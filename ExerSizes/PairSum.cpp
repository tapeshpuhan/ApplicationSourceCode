 #include <iostream>
 #include <vector>
 #include <set>
 #include <algorithm>
 #include <cstdint>
 
 using namespace std;

  int GetPairCount(const vector<int> &Data, uint32_t Num)
  {
	  using pair<int,int> = tPair;
	  multiset<int> val(Data.begin(),Data.end());
	  uint32_t count  = 0;
	  vector<tPair> _pair(Data.size()/2);
	  
	  for(auto &at : val)
	  {
		  auto bt = val.find_if(val.begin()+count,val.end(),[&](const int &p){ return Num == (p+at)});
		  if(bt != val.end())
		  {
			  tPair d = make_pair
		  }
	  }
  }
