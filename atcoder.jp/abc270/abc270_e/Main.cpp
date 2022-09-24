#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    priority_queue<pl,vector<pl>,greater<pl>> pq;
    set<int> se;
    rep(i,n) {
        cin >> a[i];
        if(a[i]!=0) {
            pq.push({a[i],-i});
            se.insert(i);
        }
    }
    ll cnt=0;
    while(k>0) {
        pl p=pq.top();
        p.first-=cnt;
        if(p.first<=0) {
            pq.pop();
            continue;
        }
        if(pq.size()*p.first<=k) {
            k-=pq.size()*p.first;
            cnt+=p.first; 
            se.erase(-p.second);
            pq.pop();
        } else {
            ll x=k/pq.size();
            k-=pq.size()*x;
            cnt+=x;
            rep(i,n) {
                if(se.find(i)==se.end()||k==0) continue;
                k--;
                a[i]--;
            }
        }
    }
    rep(i,(int)a.size()) {
        if(i) cout << " ";
        cout << max(a[i]-cnt,0LL);
    } cout << endl;
    return 0;
}