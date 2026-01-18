/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t){
        t--;
        int n,k;
        cin>>n>>k;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

    }
    

}*/


#include <bits/stdc++.h>
using namespace std;

int mex(const vector<int> &a) {
    int n = a.size();
    vector<bool> present(n + 2, false);
    for (int x : a) {
        if (x <= n + 1) present[x] = true;
    }
    for (int i = 0; i <= n + 1; i++) {
        if (!present[i]) return i;
    }
    return n + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // Perform up to min(k, 2) operations
        for (int step = 0; step < min(k, 2); step++) {
            int m = mex(a);
            vector<int> new_a(n, m);
            if (new_a == a) break; // stabilized
            a.swap(new_a);
        }

        long long ans = 0;
        for (int x : a) ans += x;
        cout << ans << "\n";
    }
    return 0;
}