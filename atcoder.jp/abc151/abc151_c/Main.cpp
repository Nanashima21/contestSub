#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m;
    cin >> n >> m;
    set<int> se;
    map<int,ll> mp;
    int tot=0;
    rep(i,m) {
        int p; string s;
        cin >> p >> s;
        if(s[0]=='A'&&mp[p]>=0) {
            se.insert(p);
            tot+=mp[p];
            mp[p]=-INF;
        } else {
            mp[p]++;
        }
    }
    cout << (int)se.size() << " " << tot << endl;
    return 0;
}