#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=1;
    int x;
    cin>>x;
    while(t<=x){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            if(i%2==1){
              cout<<"x"<<" ";
            }
            if(i%2==0){
             cout<<"-x"<<" ";
            }
        }
        if(n%2==0){
            cout<<0<<endl;
        }
       if(n%2==1)
          cout<<t<<endl;
     t++;
    }
}