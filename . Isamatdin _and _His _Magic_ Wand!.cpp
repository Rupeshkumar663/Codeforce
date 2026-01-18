#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(n);
        bool even=false;
        bool odd=false;
        for(int i=0;i<n;i++){
            cin>>nums[i];
            if(nums[i]%2==0)
                even=true;
            else
                odd=true;
        }
        if(even && odd){
         sort(nums.begin(),nums.end());
        }
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
