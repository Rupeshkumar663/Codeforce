#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s(n,' ');
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        int ones=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') ones++;
        }
        if(ones==0){
            cout<<(n+1)/2<<"\n";
            continue;
        }
        int ans=ones;
        for(int i=0;i<n;){
            if(s[i]=='1'){
                i++;
                continue;
            }
            int j=i;
            while(j<n && s[j]=='0'){
                j++;
            }
            int len=j-i;
            if(i==0 || j==n)
                ans+=len/2;
            else
                ans+=(len-1)/2;
            i=j;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
