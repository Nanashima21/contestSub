#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vector<vector<bool>> flag(h,vector<bool> (w,false));
    queue<pair<int,int>> q;

    ll cnt=0;

    rep(i,h) rep(j,w) {
        if(s[i][j]=='.') continue;
        if(flag[i][j]) continue;
        flag[i][j]=true;
        cnt++;
        q.push({i,j});
        while(!q.empty()) {
            int cx=q.front().first;
            int cy=q.front().second;
            q.pop();
            for(int x=-1;x<2;x++) {
                for(int y=-1;y<2;y++) {
                    int nx=x+cx,ny=y+cy;
                    if(nx<0||nx>=h||ny<0||ny>=w) continue;
                    if(s[nx][ny]=='.') continue;
                    if(flag[nx][ny]) continue;
                    flag[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
    }
    cout << cnt << endl;
    
    return 0;
}