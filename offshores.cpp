#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long x,y;
        cin>>n>>x>>y;
        vector<long long>a(n);
        for(int i=0;i<n;i++) 
        cin>>a[i];

        long long total=0;
        for(int i=0;i<n;i++) 
        total+=(a[i]/x)*y;

        long long result=0;
        for(int i=0;i<n;i++){
            long long cur=a[i]+(total-(a[i]/x)*y);
            result=max(result,cur);
        }
        cout<<result<<"\n";
    }
    return 0;
}
