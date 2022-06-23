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
    ll l=0,sum=0,ans=0;
    deque<ll> dq;
    rep(i,n) {
        dq.push_back(a[i]);
        sum+=a[i];
        while(sum>=k) {
            ans+=n-i;
            sum-=dq.front();
            dq.pop_front();
        }
    }
    cout << ans << endl;
    return 0;
}