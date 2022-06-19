#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    int in,num=3;
    vector<vector<int>> dist(3,vector<int> (n+1,-1));
    bool flag=false;
    while(true) {
        if(num==n+1) flag=true;
        if(!flag) cout << "? " << 1 << " " << num << endl;
        else cout << "? " << 2 << " " << num-1 << endl;
        cin >> in;
        if(!flag) {
            dist[1][num]=in;
            num++;
        } else {
            dist[2][num-1]=in;
            num--;
        }
        if(num==3) break;
    }
    int mi=1010;
    map<int,int> mp;
    for(int i=3;i<=n;i++) {
        mi=min(mi,dist[1][i]+dist[2][i]);
        mp[dist[1][i]+dist[2][i]]++;
    }
    if(mi==3) {
        if(mp[3]==2) {
            int idx1=0,idx2=0;
            rep(i,n+1) {
                if(dist[1][i]+dist[2][i]==3) {
                    if(idx1==0) idx1=i;
                    else idx2=i;
                }
            }
            if(idx1!=0&&idx2!=0) {
                cout << "? " << idx1 << " " << idx2 << endl;
                cin >> in;
                if(in>=2) mi=1;
            } 
        } else mi=1;
    }
    cout << "! " << mi << endl; 
    return 0;
}