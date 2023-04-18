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

int comp(vector<ll> &A) {
    map<int,int> mem;
    for(auto p:A) mem[p]=0;
    int sz=0;
    for(auto &p:mem) p.second=sz++;
    for(auto &p:A) p=mem[p];
    return sz;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i];
    comp(a);
    rep(i,n) cin >> b[i];
    comp(b);
    vector<pl> p;
    rep(i,n) p.push_back({a[i],-b[i]});
    sort(all(p));
    ll ans=0;
    binary_indexed_tree bit(200200);
    ll cnt=1;
    for(int i=n-1;i>=0;i--) {
        if(i!=n-1&&p[i+1]==p[i]) {
            ans+=cnt;
            cnt++;
        } else cnt=1;
        bit.add(-p[i].second,1);
        ans+=bit.sum(-p[i].second);
    }
    cout << ans << endl;
    return 0;
}