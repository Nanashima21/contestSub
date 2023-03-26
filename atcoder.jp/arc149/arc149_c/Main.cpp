#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool isprime(ll x) {
    if(x<2) return 0;
    else if(x==2) return 1;
    if(x%2==0) return 0;
    for(ll i=3;i*i<=x;i+=2) if(x%i==0) return 0;
    return 1;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> ans(n,vector<int> (n,-1));
    if(n%2==0) {
        vector<bool> flag(n*n+1,false);
        for(int i=1;i<=n;i++) {
            flag[i]=true;
            flag[n*n-1-i]=true;
            if(i%2==0) {
                ans[n/2][i-1]=i;
                ans[n/2-1][i-1]=n*n-1-i;
            } else {
                ans[n/2][i-1]=n*n-1-i;
                ans[n/2-1][i-1]=i;
            }
        }
        int x=1;
        for(int i=0;i<n/2;i++) {
            rep(j,n) if(ans[i][j]==-1) {
                while(flag[x]) x+=2;
                flag[x]=true;
                ans[i][j]=x;
            } 
        }
        int y=2;
        for(int i=n/2;i<n;i++) {
            rep(j,n) if(ans[i][j]==-1) {
                while(flag[y]) y+=2;
                flag[y]=true;
                ans[i][j]=y;
            } 
        }
    } else {
        vector<bool> flag(n*n+1,false);
        flag[1]=true; ans[n/2-1][n/2-1]=1;
        flag[8]=true; ans[n/2][n/2-1]=8;
        flag[7]=true; ans[n/2][n/2]=7;
        flag[2]=true; ans[n/2+1][n/2]=2;
        int z=3;
        for(int i=0;i<n/2-1;i++) {
            while(flag[z]||flag[n*n-z]) z++;
            flag[z]=true;
            flag[n*n-z]=true;
            if(z%2==0) {
                ans[n/2][i]=z;
                ans[n/2-1][i]=n*n-z;
            } else {
                ans[n/2-1][i]=z;
                ans[n/2][i]=n*n-z;
            }
        }
        for(int i=n/2+1;i<n;i++) {
            while(flag[z]||flag[n*n-z]) z++;
            flag[z]=true;
            flag[n*n-z]=true;
            if(z%2==0) {
                ans[n/2+1][i]=z;
                ans[n/2][i]=n*n-z;
            } else {
                ans[n/2][i]=z;
                ans[n/2+1][i]=n*n-z;
            }
        }
        int x=1;
        for(int i=0;i<n/2;i++) {
            rep(j,n) if(ans[i][j]==-1) {
                while(flag[x]) x+=2;
                flag[x]=true;
                ans[i][j]=x;
            } 
        }
        int y=2;
        for(int i=n/2;i<n;i++) {
            rep(j,n) if(ans[i][j]==-1) {
                while(flag[y]) y+=2;
                flag[y]=true;
                ans[i][j]=y;
            } 
        }
    }
    /*bool check=true;
    rep(i,n) {
        rep(j,n) {
            if(ans[i][j]>n*n) check=false;
            rep(k,4) {
                int nx=i+dx[k],ny=j+dy[k];
                if(nx<0||nx>=n||ny<0||ny>=n) continue;
                if(isprime(ans[nx][ny]+ans[i][j])) check=false;
            }
        } 
    }
    cout << n << ':' << (check ? "Yes" : "No") << endl;*/
    rep(i,n) {
        rep(j,n) {
            if(j) cout << " ";
            cout << ans[i][j];
        } cout << endl;
    }
    return 0;
}