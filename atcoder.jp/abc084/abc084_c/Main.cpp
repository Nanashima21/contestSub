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
    vector<ll> c(n-1),s(n-1),f(n-1);
    rep(i,n-1) cin >> c[i] >> s[i] >> f[i];
    for(int i=0;i<n-1;i++) {
        ll time=0;
        int cur=i;
        while(true) {
            if(time<=s[cur]) time=s[cur];
            else {
                if(time%f[cur]!=0) time=f[cur]*(time/f[cur]+1);
            }
            time+=c[cur];
            cur++;
            if(cur==n-1) break; 
        }
        cout << time << endl;
    } 
    cout << 0 << endl;
    return 0;
}