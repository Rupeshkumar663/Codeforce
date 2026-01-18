#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long s,k,m;
        cin>>s>>k>>m;
        long long temp=(m/k)*k;
        long long temp1=m-temp;
        if(temp1>s)
           cout<<0<<"\n";
        else
         cout<<s-temp1<<"\n";
    }
    return 0;
}