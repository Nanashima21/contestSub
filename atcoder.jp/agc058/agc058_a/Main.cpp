#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

bool check(vector<int> &v) {
    bool flag=true;
    for(int i=1;i<(int)v.size()-1;i++) {
        if(i%2==1) {
            if(v[i-1]>v[i]) flag=false;
        } else {
            if(v[i-1]<v[i]) flag=false;
        }
    }
    return flag;
}

int main() {
    ll n;
    cin >> n;
    vector<int> v(2*n);
    rep(i,2*n) cin >> v[i];
    vector<int> ans;
    vector<int> p=v;
    for(int i=1;i<2*n-1;i+=2) {
        if(p[i-1]<p[i]&&p[i]>p[i+1]) continue;
        if(p[i-1]<p[i+1]) {
            swap(p[i],p[i+1]);
            ans.push_back(i+1);
        } else {
            swap(p[i-1],p[i]);
            ans.push_back(i);
        }
    }
    if(p[2*n-2]>p[2*n-1]) ans.push_back(2*n-1);
    cout << (int)ans.size() << endl;
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } cout << endl;
    return 0;
}