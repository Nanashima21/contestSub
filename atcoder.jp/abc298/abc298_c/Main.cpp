#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,q;
    cin >> n >> q;
    vector<map<int,int>> mp(n);
    vector<set<int>> se(200100);
    while(q--) {
        int t,i;
        cin >> t >> i;
        if(t==1) {
            int j;
            cin >> j;
            j--;
            mp[j][i]++;
            se[i].insert(j);
        } else if(t==2) {
            int cnt=0;
            for(auto u:mp[i-1]) {
                rep(k,u.second) {
                    if(cnt) cout << " ";
                    cout << u.first;
                    cnt++;
                } 
            } cout << endl;
        } else {
            int cnt=0;
            for(auto u:se[i]) {
                if(cnt) cout << " ";
                cout << u+1;
                cnt++; 
            } cout << endl;
        }
    }
    return 0;
}