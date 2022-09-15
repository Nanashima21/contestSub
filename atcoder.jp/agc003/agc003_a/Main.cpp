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
    vector<int> v(4);
    for(auto u:s) {
        if(u=='N') v[0]++;
        if(u=='S') v[1]++;
        if(u=='E') v[2]++;
        if(u=='W') v[3]++;
    }
    bool flag=true;
    if(v[0]>0&&v[1]==0) flag=false;
    if(v[1]>0&&v[0]==0) flag=false;
    if(v[2]>0&&v[3]==0) flag=false;
    if(v[3]>0&&v[2]==0) flag=false;
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}