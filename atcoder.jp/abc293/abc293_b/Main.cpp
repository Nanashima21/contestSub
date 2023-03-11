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
    vector<bool> flag(n,false);
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i]--;
    }
    rep(i,n) {
        if(!flag[i]) {
            flag[a[i]]=true;
        }
    } 
    vector<int> v;
    rep(i,n) if(!flag[i]) v.push_back(i+1);
    cout << (int)v.size() << endl;
    rep(i,(int)v.size()) {
        if(i) cout << " ";
        cout << v[i];
    } cout << endl;
    return 0;
}