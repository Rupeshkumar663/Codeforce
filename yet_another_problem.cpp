#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<long long>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        long long x=nums[0];
        for (int i=1;i<n;i++) {
            x=__gcd(x,nums[i]);
        }
        long long result=-1;
        for(long long y=2;y<=100;y++){
            if(x%y!=0){
                result=x;
                break;
            }
        }
        if(result==-1)
        result=101; 
        cout<<result<<"\n";
    }

    return 0;
}
