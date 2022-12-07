#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<int> r(n),h(n);
    set<int> se;
    rep(i,n) {
        cin >> r[i] >> h[i];
        se.insert(r[i]);
        h[i]--;
    }
    vector<int> v,nr=r;
    for(auto u:se) v.push_back(u);
    vector<vector<int>> cnt((int)se.size(),vector<int> (3));
    rep(i,n) cnt[lower_bound(all(v),r[i])-v.begin()][h[i]]++;
    sort(all(nr));
    rep(i,n) {
        int w=0,l=0,d=-1;
        l+=nr.end()-upper_bound(all(nr),r[i]);
        w+=lower_bound(all(nr),r[i])-nr.begin();
        int it=lower_bound(all(v),r[i])-v.begin();
        if(h[i]==0) {
            d+=cnt[it][0]; w+=cnt[it][1]; l+=cnt[it][2];
        } else if(h[i]==1) {
            l+=cnt[it][0]; d+=cnt[it][1]; w+=cnt[it][2];
        } else {
            w+=cnt[it][0]; l+=cnt[it][1]; d+=cnt[it][2];
        }
        cout << w << " " << l << " " << d << endl;
    }
    return 0;
}