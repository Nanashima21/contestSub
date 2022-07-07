#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s,t;
    cin >> s >> t;
    map<char,int> mp1,mp2;
    for(char c:s) mp1[c]++; 
    for(char c:t) mp2[c]++;
    vector<int> v1,v2;
    for(auto u:mp1) v1.push_back(u.second);
    for(auto u:mp2) v2.push_back(u.second);
    sort(all(v1)); sort(all(v2));
    cout << (v1==v2 ? "Yes" : "No") << endl;
    return 0;
}