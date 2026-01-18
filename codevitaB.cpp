/*#include<bits/stdc++.h>
using namespace std;
struct Node{int r,c,d,step;};
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int m,n;cin>>m>>n;
vector<string>g(m);
for(int i=0;i<m;i++)cin>>g[i];
vector<pair<int,int>>s,t;
for(int i=0;i<m;i++)for(int j=0;j<n;j++){
if(g[i][j]=='l')s.push_back({i,j});
if(g[i][j]=='L')t.push_back({i,j});
}
int len=s.size();
auto center=[&](vector<pair<int,int>>&v){sort(v.begin(),v.end());return v[len/2];};
auto horiz=[&](vector<pair<int,int>>&v){for(auto&p:v)if(p.first!=v[0].first)return 0;return 1;};
auto in=[&](int r,int c){return r>=0&&c>=0&&r<m&&c<n;};
auto can=[&](int r,int c,int d){for(int k=0;k<len;k++){int nr=r+(d?k-len/2:0),nc=c+(d?0:k-len/2);if(!in(nr,nc)||g[nr][nc]=='B')return 0;}return 1;};
auto sc=center(s),tc=center(t);
int sd=horiz(s)?0:1,td=horiz(t)?0:1;
vector<vector<vector<int>>>vis(m,vector<vector<int>>(n,vector<int>(2)));
queue<Node>q;
q.push(Node{sc.first,sc.second,sd,0});
vis[sc.first][sc.second][sd]=1;
int dr[4]={-1,1,0,0},dc[4]={0,0,-1,1};
while(!q.empty()){
Node cur=q.front();q.pop();
int r=cur.r,c=cur.c,d=cur.d,st=cur.step;
if(r==tc.first&&c==tc.second&&d==td){cout<<st;return 0;}
for(int i=0;i<4;i++){
int nr=r+dr[i],nc=c+dc[i];
if(!in(nr,nc))continue;
if(!vis[nr][nc][d]&&can(nr,nc,d)){vis[nr][nc][d]=1;q.push(Node{nr,nc,d,st+1});}
}
int nd=1-d,ok=1;
if(!vis[r][c][nd]){
for(int i=r-len/2;i<=r+len/2&&ok;i++)
for(int j=c-len/2;j<=c+len/2&&ok;j++)
if(!in(i,j)||g[i][j]=='B')ok=0;
if(ok&&can(r,c,nd)){vis[r][c][nd]=1;q.push(Node{r,c,nd,st+1});}
}
}
cout<<"Impossible";
}
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int m,n;cin>>m>>n;vector<string>g(m);for(int i=0;i<m;i++)cin>>g[i];
vector<pair<int,int>>s,d;
for(int i=0;i<m;i++)for(int j=0;j<n;j++){
if(g[i][j]=='l')s.push_back({i,j});
if(g[i][j]=='L')d.push_back({i,j});
}
int len=s.size();queue<tuple<int,int,int,int>>q;
set<tuple<int,int,int>>vis;
int sr=s[0].first,sc=s[0].second,dr=d[0].first,dc=d[0].second;
int sd=(s[0].first==s[1].first);
int dd=(d[0].first==d[1].first);
q.push({sr,sc,sd,0});vis.insert({sr,sc,sd});
auto ok=[&](int r,int c,int dir){
for(int k=0;k<len;k++){
int nr=r+(dir?0:k),nc=c+(dir?k:0);
if(nr<0||nc<0||nr>=m||nc>=n||g[nr][nc]=='B')return 0;
}return 1;
};
while(!q.empty()){
auto [r,c,d,st]=q.front();q.pop();
if(r==dr&&c==dc&&d==dd){cout<<st;return 0;}
int drs[4]={-1,1,0,0},dcs[4]={0,0,-1,1};
for(int i=0;i<4;i++){
int nr=r+drs[i],nc=c+dcs[i];
if(!ok(nr,nc,d))continue;
if(!vis.count({nr,nc,d})){vis.insert({nr,nc,d});q.push({nr,nc,d,st+1});}
}
int nd=d^1;bool can=1;
for(int i=0;i<len;i++)for(int j=0;j<len;j++){
int nr=r+(d?0:i),nc=c+(d?i:0);
int nr2=r+(nd?0:j),nc2=c+(nd?j:0);
if(nr2<0||nc2<0||nr2>=m||nc2>=n||g[nr2][nc2]=='B'){can=0;break;}
}
if(can&&!vis.count({r,c,nd})){vis.insert({r,c,nd});q.push({r,c,nd,st+1});}
}
cout<<"Impossible";
}
