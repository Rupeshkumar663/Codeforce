#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n,m;
        vector<int>nums(m);
        for(int i=0;i<m;i++){
            cin>>nums[i];
        }
          bool result=true;
        for(int i=1;i<m;i++) {
            if(nums[i]==1)
            continue; 
            if(nums[i]!=nums[i-1]+1){
                result=false;
                break;
            }
        }
        if(!result){
            cout<<1<<endl; 
            continue;
        }
        int mx=*max_element(nums.begin(),nums.end());
        cout<<(n-mx+1)<<endl;
    }
    return 0;
}
