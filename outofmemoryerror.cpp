#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
     cin>>t;
   while(t--){
     int n,m;
     long long x;
     cin>>n>>m>>x;
    vector<long long>nums(n),temp(n,0);
    vector<int>arr(n,-1);
    for(int i=0;i<n;i++)
       cin>>nums[i];
    int s=0;
   for(int i=0;i<m;i++){
   int k;
   long long c;
    cin>>k>>c;
    --k;
   if(arr[k]!=s){
    temp[k]=0;
    arr[k]=s;
   }
   temp[k]+=c;
   if(nums[k]+temp[k]>x){
   s++;
  }
 }
    for(int i=0;i<n;i++){
    if(arr[i]!=s)
     cout<<nums[i];
    else 
    cout<<nums[i]+temp[i];
     cout<<(i+1<n?' ':'\n');
    }
  }
}
