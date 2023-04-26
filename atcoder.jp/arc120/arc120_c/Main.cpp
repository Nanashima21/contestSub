#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

struct binary_indexed_tree {
private:
    int N;
    vector<ll> bit;
public:
    binary_indexed_tree(int n): N(n) { bit.resize(N+1,0); }
    ll addition(ll x, ll y) { return (x+y); }
    void add(int x,ll a) {
        for(x++;x<=N;x+=(x&-x)) bit[x] = addition(bit[x],a);
    }
    ll sum(int x) { //[0,x]
        ll ret=0;
        for(x++;x>0;x-=(x&-x)) ret = addition(ret,bit[x]);
        return ret;
    }
};

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    map<int,queue<int>> pos;
    rep(i,n) pos[a[i]+i].push(i);
    binary_indexed_tree bit(n);
    ll ans=0;
    rep(i,n) {
        if(!pos.count(b[i]+i)||pos[b[i]+i].empty()) {
            cout << -1 << endl;
            return 0;
        } 
        int cur=pos[b[i]+i].front();
        pos[b[i]+i].pop();
        ans+=bit.sum(n-1)-bit.sum(cur);
        bit.add(cur,1);
    }
    cout << ans << endl;
    return 0;
}