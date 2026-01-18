#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        string s,p;
        cin>>n>>s>>p;
        sort(s.begin(),s.end());
        sort(p.begin(),p.end());
        if(s==p)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
