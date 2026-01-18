#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
            cout<<" ";
        }
        string result=nums[0];
        for(int i=1;i<n;i++){
            string temp=nums[i];
            if((result+temp)<(temp+result)){
                result=result+temp;
            } else{
                result=temp+result;
            }
        }
        cout<<result<<"\n";
    }
    return 0;
}