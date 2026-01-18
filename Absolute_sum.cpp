#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<long long>a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];

        long long result=0;

        long long L = a[0], R = a[n-1];

        if(L!=-1 && R!=-1){
            result=llabs(R-L);
        }else if(L!=-1&&R==-1){
            a[n-1]=L;
            result=0;
        }else if(L==-1&&R!=-1){
            a[0]=R;
            result=0;
        }else{
            a[0]=a[n-1]=0;
            result=0;
        }
        for(int i=0;i<n;i++)
            if(a[i]==-1)
             a[i]=0;

        cout<<result<<"\n";
        for(int i=0;i<n;i++)
            cout<<a[i]<<(i+1==n?'\n':' ');
    }

    return 0;
}
