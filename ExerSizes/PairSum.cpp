 #include <iostream>
 #include <vector>
 #include <set>
 #include <algorithm>
 #include <cstdint>
 #include <utility>
 using namespace std;

  size_t GetPairCount(const vector<int> &Data, uint32_t Num)
  {
	  using tPair = pair<int,int> ;
	  multiset<int> val(Data.begin(),Data.end());
	  uint32_t count  = 0;
	  vector<tPair> _pair;
	  auto it=  val.begin();
	  auto end = val.rbegin();
	  for(auto &at : val)
	  {
		  it++; 
		  auto bt = find_if(it,val.end(),[&](const int &p){ return Num == (p+at);});
		  if(bt != val.end())
		  {
			  //cout<<" 1: "<<at<<" 2: "<<*bt<<endl;
			  tPair d = make_pair(at,*bt);
			  _pair.push_back(d);
		  }
		 
	  }
	  for(auto at : _pair)
	  {
		  cout<<at.first<<"  :: ";
		  cout<<at.second<<endl;
	  }
	  return _pair.size();
  }
	
	int main()
	{
		vector<int> _v={1,3,2,2};
		cout<<" value is "<<GetPairCount(_v,4)<<endl;
		return 0;
	}
