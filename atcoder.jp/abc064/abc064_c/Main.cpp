#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<int> v(20,0);
    rep(i,n) v[a[i]/400]++;
    int cnt=0;
    rep(i,8) if(v[i]) cnt++;
    int mi=cnt,ma=cnt;
    for(int i=8;i<20;i++) {
        if(v[i]) {
            if(mi==0) mi=1;
            ma+=v[i];
        }
    }
    cout << mi << " " << ma << endl;
    return 0;
}