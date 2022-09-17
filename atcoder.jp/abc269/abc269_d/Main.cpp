#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int dx[]={-1,-1,0,0,1,1};
int dy[]={-1,0,1,-1,0,1};

int main() {
    int n;
    cin >> n;
    vector<vector<bool>> flag(2001,vector<bool> (2001,false));
    vector<pair<int,int>> p;
    rep(i,n) {
        int x,y;
        cin >> x >> y;
        x+=1000; y+=1000;
        p.push_back({x,y});
        flag[x][y]=true;
    }
    vector<vector<bool>> visited(2001,vector<bool> (2001,false));
    int ans=0;
    rep(i,n) {
        if(visited[p[i].first][p[i].second]) continue;
        visited[p[i].first][p[i].second]=true;
        queue<pair<int,int>> q;
        q.push({p[i].first,p[i].second});
        while(!q.empty()) {
            int cx=q.front().first;
            int cy=q.front().second;
            q.pop();
            rep(j,6) {
                int nx=cx+dx[j],ny=cy+dy[j];
                if(nx<0||nx>2000||ny<0||ny>2000) continue;
                if(visited[nx][ny]) continue;
                if(!flag[nx][ny]) continue;
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}