#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>nums(3);
    for(int i=0;i<3;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    int result=(nums[1]-nums[0])+(nums[2]-nums[1]);
    cout<<result;
    return 0;
}