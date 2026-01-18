#include<bits/stdc++.h>
using namespace std;
int main(){
 int n;
  cin>>n;
 vector<long long>a(n);
   for(int i=0;i<n;i++)
   cin>>a[i];
  int curr=1,ans=1;
  for(int i=1;i<n;i++){
     if(a[i]>a[i-1])
      curr++;
    else
     curr=1;
     ans=max(ans,curr);
   }
   cout<<ans;
   return 0;
}
