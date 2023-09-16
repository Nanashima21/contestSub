#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll m;
    cin >> m;
    vector<string> s(3);
    vector<int> idx(3);
    rep(i,3) idx[i]=i;
    rep(i,3) cin >> s[i];
    ll mi=INF;
    do {
        vector<set<ll>> v(10);
        rep(k,10) {
            rep(i,3) {
                rep(j,3*m) {
                    if(s[idx[i]][j%m]-'0'==k) {
                        if(v[k].find(j)==v[k].end()) {
                            v[k].insert(j);
                            break;
                        }
                    }
                }
            }
        }
        rep(i,10){
            if((int)v[i].size()==3) {
                auto it=v[i].rbegin();
                mi=min(mi,*it);
            } 
        }
    } while(next_permutation(all(idx)));
    if(mi==INF) mi=-1;
    cout << mi << endl;
    return 0;
}