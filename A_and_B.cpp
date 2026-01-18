#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==0 || n==1 || n==2){
            cout<<"0"<<"\n";
            break;
        }
        vector<string>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        for(int i=0;i<n-1;i++){
           if(nums[i]!=nums[i+1]){
            
           }
        }
       
    }
    return 0;
}
