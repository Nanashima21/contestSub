#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int n;
vector<string> str;

void f(string s) {
    if((int)s.size()==n) str.push_back(s);
    else rep(i,*max_element(all(s))-'a'+2) f(s+char('a'+i));
}

int main() {
    cin >> n;
    string s;
    s+='a';
    f(s);
    sort(all(str));
    for(auto u:str) cout << u << endl;
    return 0;
}