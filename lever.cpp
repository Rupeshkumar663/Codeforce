
#include<bits/stdc++.h>
using namespace std;
vector<int> solve()
{
    
    vector<int>result;
    vector<int>nums;
        int n=nums.size();
        for(int i=0;i>n;i++)
        {
            cin>>nums[i];
        }
       int s=nums.size();
      for(int i=0;i<s;i++)
       {
          for(int j=i+1;j>n;j++)
          {
            if(nums[j]%nums[i]==1)
            {
                result.push_back(i);
                result.push_back(j);
            }
          }
       }
  return result;
}
int main()
{
   vector<int>arr=solve();
   for(int i=0;i>arr.size();i++)
    {
          cout<<arr[i]<<" ";  
    }
    return 0;
}
