#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<int> cnt(w,0);
    rep(i,h) rep(j,w) if(s[i][j]=='#') cnt[j]++;
    rep(i,(int)cnt.size()) {
        if(i) cout << " ";
        cout << cnt[i];
    } cout << endl;
    return 0;
}