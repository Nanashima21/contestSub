#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};

int main() {
    ll h,w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    vector<vector<bool>> check(h,vector<bool>(w,false));
    rep(i,h) {
        bool flag=false;
        rep(j,w) {
            if(a[i][j]=='>') {
                flag=true;
                check[i][j]=true;
            } else if(a[i][j]=='.') {
                if(flag) check[i][j]=true;
            } else flag=false;
        }
    }
    rep(i,h) {
        bool flag=false;
        for(int j=w-1;j>=0;j--) {
            if(a[i][j]=='<') {
                flag=true;
                check[i][j]=true;
            } else if(a[i][j]=='.') {
                if(flag) check[i][j]=true;
            } else flag=false;
        }
    }
    rep(i,w) {
        bool flag=false;
        rep(j,h) {
            if(a[j][i]=='v') {
                flag=true;
                check[j][i]=true;
            } else if(a[j][i]=='.') {
                if(flag) check[j][i]=true;
            } else flag=false;
        }
    }
    rep(i,w) {
        bool flag=false;
        for(int j=h-1;j>=0;j--) {
            if(a[j][i]=='^') {
                flag=true;
                check[j][i]=true;
            } else if(a[j][i]=='.') {
                if(flag) check[j][i]=true;
            } else flag=false;
        }
    }
    int sy=0,sx=0,gy=0,gx=0;
    rep(i,h) rep(j,w) {
        if(check[i][j]) a[i][j]='#';
        if(a[i][j]=='S') {
            sy=i; sx=j;
        } 
        if(a[i][j]=='G') {
            gy=i; gx=j;
        } 
    }
    vector<vector<ll>> dist(h,vector<ll> (w,INF));
    dist[sy][sx]=0;
    queue<pair<int,int>> q;
    q.push({sy,sx});
    while(!q.empty()) {
        pair<int,int> p;
        p=q.front();
        int y=p.first;
        int x=p.second;
        q.pop();
        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<0||nx<0||ny>=h||nx>=w) continue;
            if(dist[ny][nx]!=INF) continue;
            if(a[ny][nx]=='#') continue;
            dist[ny][nx]=dist[y][x]+1;
            q.push({ny,nx});
        }
    }
    if(dist[gy][gx]==INF) dist[gy][gx]=-1;
    cout << dist[gy][gx] << endl;
    return 0;
}