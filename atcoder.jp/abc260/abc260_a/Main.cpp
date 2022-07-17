#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s;
    cin >> s;
    map<char,int> mp;
    for(char c:s) mp[c]++;
    for(auto u:mp) {
        if(u.second==1) {
            cout << u.first << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}