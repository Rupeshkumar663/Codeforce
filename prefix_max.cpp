#include <bits/stdc++.h>
using namespace std;
long long solution(const vector<int>&a){
    long long s=0;
    int maxi=0;
    for(int x:a) {
        maxi=max(maxi,x);
        s+=maxi;
    }
    return s;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++)
         cin>>nums[i];
        long long result=solution(nums);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++) {
                swap(nums[i],nums[j]);
                result=max(result,solution(nums));
                swap(nums[i],nums[j]);
            }
        }
        cout<<result<< "\n";
    }
    return 0;
}
