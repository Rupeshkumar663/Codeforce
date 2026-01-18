
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int x,y,z;
    cin>>x>>y>>z;
    int p=x&y&z;
    if(((x&y)==p)&&((y&z)==p)&&((x&z)==p)){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
    
    
 