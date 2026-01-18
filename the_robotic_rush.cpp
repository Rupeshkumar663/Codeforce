#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
  cin>>t;
  while(t--){
     int n,m,k;
      cin>>n>>m>>k;
     vector<long long>nums1(n),nums(m);
     for(int i=0;i<n;i++)
       cin>>nums1[i];
     for(int i=0;i<m;i++)
       cin>>nums[i];
    string ss;
      cin>>ss;

    sort(nums1.begin(),nums1.end());
    sort(nums.begin(),nums.end());

    vector<long long>temp(k+1,0);
    for(int i=1;i<=k;i++){
     temp[i]=temp[i-1]+(ss[i-1]=='R'?1:-1);
  }

    int alive=n;
   vector<int>arr(n,0);
   for(int i=0;i<n;i++){
   long long start=nums1[i];
   int L=0,r=k;
   while(L<r){
    int mid=(L+r)/2;
    long long p=start+temp[mid];
    if(binary_search(nums.begin(),nums.end(),p)) 
      r=mid;
   else
      L=mid+1;
   }
   if(L<=k){
    for(int j=L;j<=k;j++) 
     arr[i]=1;
   }
 }
   vector<int>result(k+1,0);
   for(int i=0;i<n;i++){
   if(!arr[i]){
   for(int j=0;j<=k;j++) 
    result[j]++;
   }
 }
  for(int i=1;i<=k;i++)
   cout<<result[i]<<(i<k?' ':'\n');
  }
}
