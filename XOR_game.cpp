#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin>>x;
    while(x--){
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        int A0=0,B0=0;
        for(int i=0;i<n;i++) {
            A0^=a[i];
            B0^=b[i];
        }
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]) {
                if((i+1)&1)
                    c1++;
                else
                    c2++;
            }
        }
        if(A0==B0) {
            cout<<"Tie\n";
            continue;
        }
        if(A0==1){
            if(c2>0)
                cout<<"Tie\n";
            else
                cout<<"Ajisai\n";
        }
        else {
            if(c1>0)
                cout<<"Tie\n";
            else
                cout<<"Mai\n";
        }
    }
    return 0;
}
