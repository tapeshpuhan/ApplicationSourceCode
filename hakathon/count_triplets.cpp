#include <bits/stdc++.h>

using namespace std;

using Triplets = std::array<long,3>;

Triplets GenerateTriples(long index, long r)
{
   Triplets t;
   t[0] = index;
   t[1] = index * r;
   t[2] = t[1] * r;
   
   return t;
}

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {

    long count = 0;
    std::map<long,long> record;
    
    if(arr.size() > 0)
    {
        long max_value = arr[arr.size()-1];
         
        for(const auto& fre : arr)
        {
            auto ret = record.insert({fre,1});
            if(ret.second == false)
            {
                record.at(fre)++;
            }
        }
        long index = arr[0];
         if(r == 1)
         {
             count = record.at(index)-2;
         }
         else
         {
        while(index <= max_value/(r*r))
        {
            Triplets t = GenerateTriples(index,r);
            index = index * r;
            cout<<t[0]<<" "<<t[1]<<" "<<t[2]<<endl;
            count += (record.at(t[0]) * record.at(t[1]) *record.at(t[2]));           
        }
        }
    }
    return count;    

}

int main()
{


    //long ans = countTriplets({1237 ,1237, 1237, 1237, 1237, 1237, 1237}, 1);
    //long ans = countTriplets({1,3,9,9,27,81}, 3);
    long ans = countTriplets({1 ,1, 1,1,}, 1);
    cout<<ans<<endl;


    return 0;
}

