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
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i]--;
    }
    vector<ll> cnt(n,INF);
    cnt[0]=0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int v=q.front();
        q.pop();
        if(cnt[a[v]]==INF) {
            cnt[a[v]]=cnt[v]+1;
            q.push(a[v]);
        }
    }
    if(cnt[1]==INF) cout << -1 << endl;
    else cout << cnt[1] << endl;
    return 0;
}