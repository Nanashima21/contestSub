#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n; string s;
    cin >> n >> s;
    deque<int> dq;
    dq.push_back(n);
    reverse(all(s));
    rep(i,n) {
        if(s[i]=='L') dq.push_back(n-i-1);
        else dq.push_front(n-i-1);
    }
    vector<int> ans;
    while(!dq.empty()) {
        ans.push_back(dq.front());
        dq.pop_front();
    }
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } cout << endl;
    return 0;
}