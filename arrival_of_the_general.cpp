#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int count=0;
    for(int i=1;i<n;i++){
        if(nums[i-1]==nums[i]){
            count==0;
        }
        else if(nums[i-1]<nums[i]){
            int temp=nums[i-1];
            nums[i-1]=nums[i];
            nums[i]=temp;
        }
    }
    int count2=0;
    for(int j=n-1;j>=0;j--){
        if(nums[j]==nums[j-1]){
            count2=0;
        }
        else if(nums[j-1]<nums[j]){
            int temp=nums[j-1];
            nums[j-1]=nums[j];
            nums[j]=temp;
        }
    }
    cout<<(count+count2-1)<<endl;
    return 0;
}