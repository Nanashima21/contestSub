#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n; string s;
    cin >> n >> s;
    vector<int> cnt(3,0);
    rep(i,n) {
        if(s[i]=='R') cnt[0]++;
        if(s[i]=='G') cnt[1]++;
        if(s[i]=='B') cnt[2]++;
    }
    int ans=0;
    rep(i,3) ans+=cnt[i]%2;
    cout << ans << endl;
    return 0;
}