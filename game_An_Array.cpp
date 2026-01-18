/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(2*n,0);
        for(int i=1;i<=n;i++){
            for(int j=0;j<2*n;j++){
                if(nums[j]==0 && nums[i+j]==0 && i+j<2*n){
                    nums[j]=nums[i+j]=i;
                    break;
                }
            }
        }
        for(int i=0;i<2*n;i++){
            cout<<nums[i]<<" ";
        }
    }
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        int m=*min_element(nums.begin(),nums.end())+*max_element(nums.begin(),nums.end());
        int count=0;
        int countb=0;
        for(int i=1;i<=m;i++){
            int mid=nums[n/2];
            for(int i=0;i<n;i++){
                if(nums[i]==mid){
                      if(m%2!=0){
                        count++;
                      }
                      else{
                        countb++;
                      }
                      
                      nums[i]=mid-1;
                }
            }
        }
        

        
    }
    return 0;
}