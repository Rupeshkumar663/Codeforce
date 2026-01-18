#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int count=0,countn=0,n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
            if(nums[i]==0)count++;
            if(nums[i]==-1)countn++;
        }
        if(countn%2==0)cout<<count<<"\n";
        else cout<<count+2<<"\n";
    }
    return 0;
}
