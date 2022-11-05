#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int main() {
    ll h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<pair<int,int>> p;
    rep(i,h) rep(j,w) {
        if(s[i][j]=='S') {
            rep(k,4) {
                int nx=i+dx[k],ny=j+dy[k];
                if(nx<0||nx>=h||ny<0||ny>=w) continue;
                if(s[nx][ny]=='#') continue;
                p.push_back({nx,ny});
            }
        }
    }
    rep(i,(int)p.size()) {
        queue<pair<int,int>> q;
        q.push({p[i].first,p[i].second});
        vector<vector<bool>> flag(h,vector<bool> (w,false));
        flag[p[i].first][p[i].second]=true;
        while(!q.empty()) {
            int cx=q.front().first;
            int cy=q.front().second;
            q.pop();
            rep(k,4) {
                int nx=cx+dx[k],ny=cy+dy[k];
                if(nx<0||nx>=h||ny<0||ny>=w) continue;
                if(flag[nx][ny]) continue;
                if(s[nx][ny]!='.') continue;
                flag[nx][ny]=true;
                q.push({nx,ny});
            }
        }
        rep(j,(int)p.size()) {
            if(i==j) continue;
            if(flag[p[j].first][p[j].second]) {
                std::cout << "Yes" << endl;
                return 0;
            }
        }
    }
    std::cout << "No" << endl;
    return 0;
}