#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; 
    if(!(cin>>t))
     return 0;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a==b && b==c && c==d) 
         cout<<"YES\n";
        else 
        cout<<"NO\n";
    }
    return 0;
}
