#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int k,n,q;
    cin >> n >> k >> q;
    vector<int> flag(n+1),a(k),l(q);
    rep(i,k) {
        cin >> a[i];
        flag[a[i]]=1;
    }
    rep(i,q) {
        cin >> l[i];
        int cnt=0,j=0;
        while(true) {
            if(flag[j]) cnt++;
            if(cnt==l[i]) break;
            j++;
        }
        if(j==n) continue;
        else {
            if(flag[j+1]) continue;
            else {
                flag[j+1]=1;
                flag[j]=0;
            }
        }
    }
    vector<int> ans;
    rep(i,n+1) if(flag[i]) ans.push_back(i);
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } cout << endl;
    return 0;
}