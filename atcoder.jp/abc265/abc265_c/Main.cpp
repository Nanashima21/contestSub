#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int main() {
    ll h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    queue<pair<int,int>> q;
    q.push({0,0});
    vector<vector<bool>> flag(h,vector<bool> (w,false));
    while(!q.empty()) {
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        int nx=0,ny=0;
        if(s[cx][cy]=='U') {
            nx=cx-1; ny=cy;
        } else if(s[cx][cy]=='D') {
            nx=cx+1; ny=cy;
        } else if(s[cx][cy]=='R') {
            nx=cx; ny=cy+1;
        } else if(s[cx][cy]=='L') {
            nx=cx; ny=cy-1;
        }
        if(nx<0||nx>=h||ny<0||ny>=w) {
            cout << cx+1 << " " << cy+1 << endl;
            return 0;
        }
        if(flag[nx][ny]) {
            cout << -1 << endl;
            return 0;
        }
        flag[nx][ny]=true;
        q.push({nx,ny});
    }
    return 0;
}