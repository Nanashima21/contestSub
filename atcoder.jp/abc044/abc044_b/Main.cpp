#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string w;
    cin >> w;
    map<char,int> mp;
    for(auto u:w) mp[u]++;
    bool flag=true;
    for(auto u:mp) if(u.second%2!=0) flag=false;
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}