#include<bits/stdc++.h>
using namespace std;
int main(){
int R,C;cin>>R>>C;
cin.ignore();
string line;getline(cin,line);
stringstream ss(line);
vector<vector<vector<int>>>a(R,vector<vector<int>>(C));
int num=1;
for(int i=0;i<R;i++)for(int j=0;j<C;j++)a[i][j].push_back(num++);
string s;
while(ss>>s){
if(s[0]=='v'){
int k=stoi(s.substr(1));
vector<vector<vector<int>>>b(R,vector<vector<int>>(k));
for(int i=0;i<R;i++){
for(int j=0;j<k;j++)b[i][j]=a[i][j];
for(int j=k;j<C;j++){
int nj=k-(j-k)-1;
if(nj>=0)for(auto x:a[i][j])b[i][nj].insert(b[i][nj].begin(),x);
}
}
a=b;C=k;
}
else if(s[0]=='h'){
int k=stoi(s.substr(1));
vector<vector<vector<int>>>b(k,vector<vector<int>>(C));
for(int i=0;i<k;i++)b[i]=a[i];
for(int i=k;i<R;i++){
int ni=k-(i-k)-1;
if(ni>=0)for(int j=0;j<C;j++)for(auto x:a[i][j])b[ni][j].insert(b[ni][j].begin(),x);
}
a=b;R=k;
}
}
cout<<a[0][0].back()<<" "<<a[0][0].front();
}
