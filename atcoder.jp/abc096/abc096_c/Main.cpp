#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    bool flag=true;
    rep(i,h) rep(j,w) {
        if(s[i][j]=='#') {
            bool check=false;
            rep(k,4) {
                int ni=i+dx[k],nj=j+dy[k];
                if(ni<0||ni>=h||nj<0||nj>=w) continue;
                if(s[ni][nj]=='#') check=true;
            }
            if(!check) flag=false;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}