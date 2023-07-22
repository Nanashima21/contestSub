#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int main() {
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    queue<pair<pair<int,int>,int>> q;
    rep(i,4) q.push({{1,1},i});
    vector<vector<vector<bool>>> flag(n,vector<vector<bool>> (m,vector<bool> (4,false)));
    rep(i,4) flag[1][1][i]=true;
    while(!q.empty()) {
        int cx=q.front().first.first;
        int cy=q.front().first.second;
        int cd=q.front().second;
        q.pop();
        int nx=cx+dx[cd],ny=cy+dy[cd];
        if(s[nx][ny]=='#') {
            rep(i,4) {
                int nnx=cx+dx[i],nny=cy+dy[i];
                if(s[nnx][nny]=='#') continue;
                if(flag[nnx][nny][i]) continue;
                flag[nnx][nny][i]=true;
                q.push({{nnx,nny},i});
            }
        } else {
            if(flag[nx][ny][cd]) continue;
            flag[nx][ny][cd]=true;
            q.push({{nx,ny},cd});
        }
    }
    ll cnt=0;
    rep(i,n) rep(j,m) {
        bool check=false;
        rep(k,4) check|=flag[i][j][k];
        if(check) cnt++;
    }
    cout << cnt << endl;
    return 0;
}