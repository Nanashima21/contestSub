#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<int> v(4);
    rep(i,4) cin >> v[i];
    int mi=min(v[1],v[2]);
    bool flag=true;
    if(v[1]+v[2]==0&&v[0]!=0&&v[3]!=0) flag=false; 
    if(abs(v[1]-v[2])>1) flag=false;
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}