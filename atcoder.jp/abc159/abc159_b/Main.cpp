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
    int n=(int)s.size();
    string ns=s;
    reverse(all(ns));
    bool flag=true;
    if(ns!=s) flag=false; 
    string s1=s.substr(0,(n-1)/2),s2=s.substr((n+2)/2);
    if(s1!=s2) flag=false;
    cout << (flag ? "Yes" : "No") << endl; 
    return 0;
}