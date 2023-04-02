#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,l;
    cin >> n >> l;
    vector<ll> a(n);
    bool flag=false;
    int idx=0;
    rep(i,n) {
        cin >> a[i];
        if(i>0&&a[i-1]+a[i]>=l) {
            flag=true;
            idx=i-1;
        } 
    }
    if(!flag) cout << "Impossible" << endl;
    else {
        cout << "Possible" << endl;
        rep(i,idx) cout << i+1 << endl;
        for(int i=n-2;i>=idx;i--) cout << i+1 << endl;
    }
    return 0;
}