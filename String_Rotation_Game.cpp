#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]!=s[(i+1)%n])
                count++;
        }

        if(count==0)
            cout<<1<<endl;
        else
            cout<<min(n, count+1)<<endl;
    }
}