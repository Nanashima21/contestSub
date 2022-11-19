#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,k;
    cin >> n >> k;
    deque<int> dq;
    rep(i,n) {
        int a;
        cin >> a;
        dq.push_back(a);
    }
    rep(i,k) {
        dq.pop_front();
        dq.push_back(0);
    }
    rep(i,n) {
        if(i) cout << " ";
        cout << dq.front();
        dq.pop_front();
    } cout << endl;
    return 0;
}