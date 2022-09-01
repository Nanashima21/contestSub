#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    queue<pair<int,int>> q;
    q.push({0,0});
    vector<vector<ll>> dist(h,vector<ll> (w,INF));
    dist[0][0]=0;
    while(!q.empty()) {
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        rep(i,4) {
            int nx=dx[i]+cx,ny=dy[i]+cy;
            if(nx<0||nx>=h||ny<0||ny>=w) continue;
            if(s[nx][ny]=='#') continue;
            if(dist[nx][ny]!=INF) continue; 
            dist[nx][ny]=dist[cx][cy]+1;
            q.push({nx,ny});
        }
    }
    int cnt=0;
    rep(i,h) rep(j,w) if(s[i][j]=='#') cnt++;
    if(dist[h-1][w-1]==INF) cout << -1 << endl;
    else cout << h*w-dist[h-1][w-1]-cnt-1 << endl;
    return 0;
}