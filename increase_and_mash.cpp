#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
         cin >> a[i];
        }
        unordered_set<int>s(a.begin(),a.end());
        int x=s.size();
        cout<<2*x-1<<"\n";
    }
    return 0;
}
