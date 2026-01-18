#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<long long>nums(n);
        for(int i=0;i<n;i++)
         cin>>nums[i];
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int result=1,cur=1;
        for (int i=1;i<(int)nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                cur++;
            } else{
                cur=1;
            }
            result=max(result,cur);
        }
        cout<<result<<"\n";
    }
    return 0;
}
