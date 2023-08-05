#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum=0;
    rep(i,n) {
        cin >> a[i];
        sum+=a[i];
    }
    sort(all(a));
    sum/=n;
    ll cnt1=0,cnt2=0;
    rep(i,n) {
        if(a[i]<sum) cnt1+=sum-a[i];
        else if(a[i]>sum) cnt2+=a[i]-sum-1;
    }
    cout << max(cnt1,cnt2) << endl;
    return 0;
}