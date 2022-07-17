#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

ll n,x,y;

ll dfs(ll n,ll num,int c) {
    if(n==1) {
        if(c==0) return 0;
        else return num;
    } else {
        if(c==0) return dfs(n-1,num,0)+dfs(n,num*x,1);
        else return dfs(n-1,num,0)+dfs(n-1,num*y,1);
    }
}

int main() {
    cin >> n >> x >> y;
    cout << dfs(n,1,0) << endl;
    return 0;
}