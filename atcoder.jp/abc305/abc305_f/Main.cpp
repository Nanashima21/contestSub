#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> vec(1);
    vector<bool> visited(n,false);
    visited[0]=true;
    int cur=0;
    while(true) {
        int in;
        cin >> in;
        if(in==-1) return 0;
        vector<int> v(in);
        rep(i,in) {
            cin >> v[i];
            v[i]--;
        }
        bool check=true;
        rep(i,in) {
            if(visited[v[i]]) continue;
            visited[v[i]]=true;
            vec.push_back(v[i]);
            cur=v[i];
            check=false;
            break;
        } 
        if(check) {
            vec.pop_back();
            cur=vec.back();
        }
        cout << cur+1 << endl;
        if(cur+1==n) break;
    }
    string s;
    cin >> s;
    return 0;
}