#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int dx[]={1,-1,1,-1};
int dy[]={1,-1,-1,1};

int main() {
    int h,w;
    cin >> h >> w;
    int n=min(h,w);
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<int> ans(n);
    rep(i,h) rep(j,w) {
        if(s[i][j]=='.') continue;
        int cnt=1;
        while(true) {
            int val=0;
            rep(k,4) {
                int nx=i+dx[k]*cnt,ny=j+dy[k]*cnt;
                if(nx<0||nx>=h||ny<0||ny>=w) break;
                if(s[nx][ny]=='.') break;
                val++;
            }
            if(val!=4) break;
            cnt++;
        }
        if(cnt>=2) ans[cnt-2]++;
    }
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } cout << endl;
    return 0;
}