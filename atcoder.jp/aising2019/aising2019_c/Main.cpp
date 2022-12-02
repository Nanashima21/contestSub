#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<vector<bool>> flag(h,vector<bool> (w,false));
    ll ans=0;
    rep(i,h) rep(j,w) {
        if(s[i][j]=='.') continue;
        if(flag[i][j]) continue;
        flag[i][j]=true;
        queue<pair<int,int>> q;
        q.push({i,j});
        ll cnt0=0,cnt1=0;
        while(!q.empty()) {
            int cx=q.front().first;
            int cy=q.front().second;
            if(s[cx][cy]=='#') cnt0++;
            else cnt1++;
            q.pop();
            rep(k,4) {
                int nx=cx+dx[k],ny=cy+dy[k];
                if(nx<0||nx>=h||ny<0||ny>=w) continue;
                if(s[cx][cy]=='.'&&s[nx][ny]=='.') continue;
                if(s[cx][cy]=='#'&&s[nx][ny]=='#') continue;
                if(flag[nx][ny]) continue;
                flag[nx][ny]=true;
                q.push({nx,ny});
            }
        }
        ans+=cnt0*cnt1;
    }
    cout << ans << endl;
    return 0;
}