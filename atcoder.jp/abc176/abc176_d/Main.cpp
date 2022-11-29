#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
    int h,w;
    cin >> h >> w;
    int sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;
    sx--; sy--; gx--; gy--;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    deque<pair<int,int>> dq;
    dq.push_back({sx,sy});
    vector<vector<bool>> flag(h,vector<bool> (w,false));
    flag[sx][sy]=true;
    vector<vector<ll>> cnt(h,vector<ll> (w,INF));
    cnt[sx][sy]=0;
    while(!dq.empty()) {
        int x=dq.front().first;
        int y=dq.front().second;
        dq.pop_front();
        rep(i,4) {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0||nx>=h||ny<0||ny>=w) continue;
            if(s[nx][ny]=='#') continue;
            if(cnt[nx][ny]>cnt[x][y]) {
                flag[nx][ny]=true;
                cnt[nx][ny]=cnt[x][y];
                dq.push_front({nx,ny});
            }
        }
        for(int i=-2;i<=2;i++) {
            for(int j=-2;j<=2;j++) {
                int nx=x+i,ny=y+j;
                if(nx<0||nx>=h||ny<0||ny>=w) continue;
                if(s[nx][ny]=='#') continue;
                if(flag[nx][ny]) continue;
                flag[nx][ny]=true;
                cnt[nx][ny]=min(cnt[nx][ny],cnt[x][y]+1);
                dq.push_back({nx,ny});
            }
        }
    }
    if(!flag[gx][gy]) cout << -1 << endl;
    else cout << cnt[gx][gy] << endl;
    return 0;
}