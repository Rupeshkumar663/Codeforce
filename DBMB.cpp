#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s,x;
        cin>>n>>s>>x;
         int sum=0;
         vector<int>nums(n);
         for(int i=0;i<n;i++){
            cin>>nums[i];
            sum+=nums[i];
         }
         
         if(sum==s){
            cout<<"YES"<<endl;
         } else if(sum<s){
            int temp=(s-sum);
             if(temp%x==0){
                cout<<"YES"<<endl;
             } else{
                cout<<"NO"<<endl;
             }
         } else{
            cout<<"NO"<<endl;
         }
         
    }
    return 0;
}