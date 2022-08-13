#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int r,c;
    cin >> r >> c;
    bool flag=true;
    if(r==2||r==14) {
        if(2<=c&&c<=14) flag=false;
    } else if(r==4||r==12) {
        if(4<=c&&c<=12) flag=false;
        if(c%2==0) flag=false;
    } else if(r==6||r==10) {
        if(6<=c&&c<=10) flag=false;
        if(c%2==0) flag=false;
    } else if(r==8) {
        if(c==8) flag=false;
        if(c%2==0) flag=false;
    } else if(r==3||r==13) {
        if(c==2||c==14) flag=false;
    } else if(r==5||r==11) {
        if(c==2||c==4||c==12||c==14) flag=false;
    } else if(r==7||r==9) {
        if(c==2||c==4||c==6||c==10||c==12||c==14) flag=false;
    }
    cout << (flag ? "black" : "white") << endl;
    return 0;
}