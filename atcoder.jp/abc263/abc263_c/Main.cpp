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
    vector<int> v;
    rep(i,m) v.push_back(i+1);
    set<vector<int>> se; 
    do {
        vector<int> vv;
        rep(i,n) vv.push_back(v[i]);
        sort(all(vv));
        se.insert(vv);
    } while(next_permutation(all(v)));
    for(auto u:se) {
        rep(i,(int)u.size()) {
            if(i) cout << " ";
            cout << u[i];
        } cout << endl;
    }
    return 0;
}