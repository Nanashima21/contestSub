#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string a,b;
    cin >> a >> b;
    int sa=0,sb=0;
    for(char c:a) sa+=c-'0'; 
    for(char c:b) sb+=c-'0';
    cout << max(sa,sb) << endl;
    return 0;
}