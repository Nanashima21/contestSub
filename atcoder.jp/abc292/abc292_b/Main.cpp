#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,q;
    cin >> n >> q;
    vector<int> flag(n,0);
    rep(i,q) {
        int t,x;
        cin >> t >> x;
        x--;
        if(t==1) flag[x]++;
        else if(t==2) flag[x]+=2;
        else cout << (flag[x]>=2 ? "Yes" : "No") << '\n'; 
    }
    return 0;
}