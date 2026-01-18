#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        sort(nums.begin(),nums.end());
        int maxi=0;
        for(int i=0;i<n-1;i+=2){
            int result=nums[i+1]-nums[i];
            maxi=max(maxi,result);
        }
        cout<<maxi<<"\n";
    }
    return 0;
}
