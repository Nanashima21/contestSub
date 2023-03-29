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
    rep(i,n) cin >> a[i]; 
    while(k--) {
        vector<ll> cnt(n,0);
        rep(i,n) {
            cnt[max(0LL,i-a[i])]++;
            if(i+a[i]+1<n) cnt[i+a[i]+1]--;
        }
        bool flag=true;
        if(cnt[0]!=n) flag=false;
        for(int i=1;i<n;i++) {
            cnt[i]+=cnt[i-1];
            if(cnt[i]!=n) flag=false; 
        }
        swap(a,cnt);
        if(flag) break;
    }
    rep(i,(int)a.size()) {
        if(i) cout << " ";
        cout << a[i];
    } cout << endl;
    return 0;
}