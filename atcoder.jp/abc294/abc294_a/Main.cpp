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
    vector<ll> v;
    rep(i,n) {
        int a;
        cin >> a;
        if(a%2==0) v.push_back(a);
    }
    rep(i,(int)v.size()) {
        if(i) cout << " ";
        cout << v[i];
    } cout << endl;
    return 0;
}