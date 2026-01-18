#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int k=0;k<n;k++){
            cin>>nums[k];
        }

        int maxi=0;
        vector<int>result(n+1,0);
        for(int i=0;i<n;i++){
            result[i+1]=result[i]+nums[i];
        }

        for(int l=0;l<n;l++){
            for(int r=l;r<n;r++){
                int sum=result[r+1]-result[l];
                int x=r-l+1;
                int temp=sum/x;
                maxi=max(maxi,temp);
            }
        }
        cout<<maxi<<"\n";
    }
    return 0;
}
