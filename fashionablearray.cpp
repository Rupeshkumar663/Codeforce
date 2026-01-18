
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
void solve(){
    int n,i,j,c1,c2,mn=51;
    cin>>n;
    vector<int>v(n);
    for(i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    for(i=0;i<n;i++){
        for(j=n-1;j>=i;j--){
            if((v[i]+v[j])%2==0){
                mn=min(mn,i+(n-1-j));
            }
        }
    }
    cout<<mn<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
     solve();
    }


  return 0;
}




