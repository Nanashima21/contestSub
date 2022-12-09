#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
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
    int n;
    cin >> n;
    vector<ll> a(n),b(2*n);
    rep(i,n) {
        cin >> a[i];
        b[i]=b[i+n]=a[i];
    }
    binary_indexed_tree bit(n);
    vector<ll> ans;
    ll tot=0;
    for(int i=0;i<n;i++) {
        tot+=bit.sum(n-1)-bit.sum(b[i]);
        bit.add(b[i],1);
    }
    cout << tot << endl;
    for(int i=n;i<2*n-1;i++) {
        tot-=bit.sum(b[i]-1);
        tot+=bit.sum(n-1)-bit.sum(b[i]);
        cout << tot << endl;
    }
    return 0;
}