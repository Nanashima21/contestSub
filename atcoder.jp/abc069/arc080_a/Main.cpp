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
    int cnt4=0,cnt=0;
    rep(i,n) {
        if(a[i]%4==0) cnt4++;
        else if(a[i]%2==1) cnt++;
    }
    cout << ((cnt4>=cnt||cnt4>=n/2) ? "Yes" : "No") << endl; 
    return 0;
}