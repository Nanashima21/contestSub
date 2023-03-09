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
    int n,m;
    cin >> n >> m;
    vector<int> l(m),r(m),x(m);
    vector<pair<int,int>> p;
    rep(i,m) {
        cin >> l[i] >> r[i] >> x[i];
        l[i]--; r[i]--;
        p.push_back({r[i],i});
    }
    sort(all(p));
    vector<int> ans(n,0);
    binary_indexed_tree bit(n);
    deque<int> dq;
    int q=0;
    rep(i,m) {
        int idx=p[i].second;
        while(q<=r[idx]) dq.push_back(q++);
        
        int k=x[idx]-bit.sum(r[idx]);
        if(l[idx]!=0) k+=bit.sum(l[idx]-1);
        //cout << (bit.sum(r[idx])-bit.sum(l[idx]-1)) << " " << r[idx] << " " << l[idx]-1 << endl;
        rep(_,k) {
            int x=dq.back();
            dq.pop_back();
            ans[x]=1;
            bit.add(x,1);
        }
    }
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } cout << endl;
    return 0;
}