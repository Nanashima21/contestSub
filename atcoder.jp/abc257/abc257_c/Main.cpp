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
    string s;
    cin >> s;
    vector<ll> w(n),c,a;
    rep(i,n) {
        cin >> w[i];
        if(s[i]=='0') c.push_back(w[i]);
        else a.push_back(w[i]);
    }
    sort(all(a));
    sort(all(c));
    int ans=0;
    rep(i,n) {
        for(int k=-1;k<=1;k++) {
            int it1=lower_bound(all(a),w[i]+k)-a.begin();
            int it2=lower_bound(all(c),w[i]+k)-c.begin();
            ans=max(ans,(int)a.size()-it1+it2);
        }
    }
    cout << ans << endl;
    return 0;
}