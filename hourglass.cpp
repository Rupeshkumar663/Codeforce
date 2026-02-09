#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long s,k,m;
        cin>>s>>k>>m;
        if(m<s){
            cout<<s-m<<"\n";
            continue;
        }
        long long r=m%k;
        if(r>s)
            cout<<0<<"\n";
        else
            cout<<s-r<<"\n";
    }
    return 0;
}
