/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int>b(n);
        for(int i=0;i<n;i++){
         cin>>b[i];
        }
        int maxi=0;
        for(int i=0;i<n;i++) {
            int count=1;
            int l=b[i];
            for(int j=1;j<n;j++) {
                int x=(i+j)%n;
                if(b[x]>l){
                    l=b[x];
                    count++;
                }
            }
            maxi=max(maxi,count);
        }
        cout<<maxi<<"\n";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
int n;
cin>>n;
vector<int>b(n);
for(int i=0;i<n;i++)cin>>b[i];
int maxi=0;
for(int i=0;i<n;i++){
for(int skipFirst=0;skipFirst<=1;skipFirst++){
int count=0,last=0;
for(int j=0;j<n;j++){
int x=(i+j)%n;
if(j==0&&skipFirst)continue;
if(b[x]>last){
last=b[x];
count++;
}
}
maxi=max(maxi,count);
}
}
cout<<maxi<<"\n";
}
return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    set<int>s;
    for(int i=0;i<n;i++) {
        int b;
        cin>>b;
        s.insert(b);
    }
    cout<<s.size()<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}