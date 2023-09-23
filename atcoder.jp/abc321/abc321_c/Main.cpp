#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll k;
    cin >> k;
    vector<ll> v;
    queue<ll> q;
    rep(i,10) q.push(i);
    while(!q.empty()) {
        ll cv=q.front();
        v.push_back(cv);
        q.pop();
        for(int i=cv%10-1;i>=0;i--) {
            q.push(cv*10+i);
        }
    }
    sort(all(v));
    cout << v[k] << endl;
    return 0;
}