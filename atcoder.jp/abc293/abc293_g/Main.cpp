#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

vector<ll> vec;

struct Mo {
private:
    vector<int> l,r;
    vector<ll> v_;
    ll sz=0,res=0;
public:
    vector<ll> ans,cnt;
    Mo(vector<ll> &v):v_(v) {}
    void query(const int ql,const int qr) {
        l.push_back(ql);
        r.push_back(qr);
        sz++;
    }
    void add(const int i) {
        cnt[v_[i]]++;
        if(cnt[v_[i]]>=3) res+=vec[cnt[v_[i]]-3];
    }
    void del(const int i) {
        if(cnt[v_[i]]>=3) res-=vec[cnt[v_[i]]-3];
        cnt[v_[i]]--;
    }
    void solve() {
        vector<int> ord(sz);
        iota(all(ord),0);
        const int wid=(int)sqrt((int)v_.size());
        sort(all(ord),[&](const int a,const int b) {
            const int c=l[a]/wid,d=l[b]/wid;
            return (c==d) ? ((c&1) ? (r[b]<r[a]):(r[a]<r[b])):(c<d);
        });
        ans.resize(sz);
        cnt.resize(200200);
        int nl=0,nr=0;
        for(auto i:ord) {
            while(nl>l[i]) add(--nl);
            while(nr<r[i]) add(nr++);
            while(nl<l[i]) del(nl++);
            while(nr>r[i]) del(--nr);
            ans[i]=res;
        }
    }
    //Mo mo(v);
};

int main() {
    int n,q;
    cin >> n >> q;
    vector<ll> v(n);
    rep(i,n) {
        cin >> v[i];
        v[i]--;
    }
    vec.resize(200200);
    vec[0]=1;
    for(ll i=1;i<=200020;i++) vec[i]=vec[i-1]+i+1;
    Mo mo(v);
    rep(i,q) {
        int l,r;
        cin >> l >> r;
        mo.query(l-1,r);
    }
    mo.solve();
    const auto& ans=mo.ans;
    rep(i,q) cout << ans[i] << "\n";
    return 0;
}