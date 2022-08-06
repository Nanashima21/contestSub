#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    vector<int> v(5);
    rep(i,5) cin >> v[i];
    sort(all(v));
    if(v[0]==v[1]&&v[1]==v[2]&&v[2]!=v[3]&&v[3]==v[4]) cout << "Yes" << endl;
    else if(v[0]==v[1]&&v[1]!=v[2]&&v[2]==v[3]&&v[3]==v[4]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}