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
        vector<int>result;
        int x=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')
               x++;
        }
        int y=n-x;
        if(x%2==0){
            for(int i=0;i<n;i++){
                if(s[i]=='1')
                 result.push_back(i+1);
            }
        }
        else if(y%2==1){
            for(int i=0;i<n;i++){
                if(s[i]=='0')
                    result.push_back(i+1);
            }
        }
        else{
            cout<<-1<<endl;
            continue;
        }
        cout<<result.size()<<endl;
        for(int x:result)
            cout<<x<<" ";
        cout<<endl;
    }
}