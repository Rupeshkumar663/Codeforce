#include<bits/stdc++.h>
using namespace std;
bool Palindrome(const string &s) {
    for(int k=0,j=s.size()-1;k<j;k++,j--)
        if(s[k]!=s[j])
         return false;
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       string s;
       cin>>s;
        if(Palindrome(s)){
            cout<<0<<"\n\n";
            continue;
        }
        vector<int> p;
        for(int i=0;i<n;i++) {
            if(s[i]=='0')
             p.push_back(i+1);
        }
        cout<<p.size()<<"\n";
        for(int i=0;i<(int)p.size();i++) {
            if(i)
            cout<<" ";
            cout<<p[i];
        }
        cout<<"\n";

    }
    return 0;
}
