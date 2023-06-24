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
    vector<int> cnt(n+1,0);
    rep(i,n) {
        if(s[i]=='(') dq.push_back(i);
        if(s[i]==')'&&!dq.empty()) {
            cnt[dq.back()]++;
            cnt[i+1]--;
            dq.pop_back();
        }

    }
    for(int i=1;i<n;i++) cnt[i]+=cnt[i-1];
    string str;
    rep(i,n) if(cnt[i]==0) str+=s[i];
    cout << str << endl;
    return 0;
}