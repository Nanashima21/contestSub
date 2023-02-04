#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int N,M,D,K;
vector<vector<pair<int,ll>>> G; 
vector<pair<int,int>> P;
vector<int> R,NR,U,V,DEG;
vector<ll> W;
map<pair<int,int>,int> EMP;

const double Limit_time=5.80*CLOCKS_PER_SEC;

int Randint(int a,int b) {
    return a+rand()%(b-a+1);
}

double Randdouble() {
    return 1.0*rand()/RAND_MAX;
}

void input() {
    cin >> N >> M >> D >> K;
    G.resize(N,vector<pair<int,ll>> ());
    U.resize(M); V.resize(M); W.resize(M);
    R.resize(M); NR.resize(M); DEG.resize(M);
    rep(i,M) {
        cin >> U[i] >> V[i] >> W[i];
        U[i]--; V[i]--;
        G[U[i]].push_back({V[i],W[i]});
        G[V[i]].push_back({U[i],W[i]});
        EMP[{U[i],V[i]}]=i;
        EMP[{V[i],U[i]}]=i;
        DEG[U[i]]++;
        DEG[V[i]]++;
    }
    rep(i,N) {
        int x,y;
        cin >> x >> y;
        P.push_back({x,y});
    }
}

void output() {
    rep(i,M) {
        if(i) cout << " ";
        cout << R[i];
    } cout << endl;
}

double dist(pair<int,int> p1,pair<int,int> p2) {
    return sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
}

struct UnionFind {
    vector<ll> v;
    UnionFind(ll n=0): v(n,-1) {}
    int find(ll x) {
        if(v[x]<0) return x;
        return v[x]=find(v[x]);
    }
    bool unite(ll x,ll y) {
        x=find(x);
        y=find(y);
        if(x==y) return false;
        if(v[x]>v[y]) swap(x,y);
        v[x]+=v[y];
        v[y]=x;
        return true;
    }
    bool same(ll x,ll y) { return find(x)==find(y); }
    ll size(ll x) { return -v[find(x)]; }
};

void solve() {
    std::random_device get_rand_dev;
    std::mt19937 get_rand_mt(get_rand_dev());
    double min_dist=INF;
    //ll min_cost=INF;
    ll lim=M/D;
    vector<int> day,edge;
    rep(i,D) day.push_back(i);
    rep(i,M) edge.push_back(i);
    while(clock()<Limit_time) {
        rep(i,N) NR[i]=0;
        vector<vector<int>> deg(D,vector<int> (N,0));
        vector<int> cnt(D,0);
        vector<ll> dsum(D,0);
        ll cost=0;
        std::shuffle(all(edge),get_rand_mt);
        for(int e=0;e<M;e++) {
            int i=edge[e];
            std::shuffle(all(day),get_rand_mt);
            for(int j=0;j<D;j++) {
                if(cnt[day[j]]>=lim) continue;
                if(deg[day[j]][U[i]]==0&&deg[day[j]][V[i]]==0) {
                    deg[day[j]][U[i]]++;
                    deg[day[j]][V[i]]++;
                    NR[i]=day[j]+1;
                    cnt[day[j]]++;
                    dsum[day[j]]+=W[i];
                    break;
                }
            }
        }
        for(int e=0;e<M;e++) {
            int i=edge[e];
            for(int dnum=1;dnum<min(DEG[V[i]],DEG[U[i]]);dnum++) {
                if(NR[i]!=0) break;
                for(int j=0;j<D;j++) {
                    if(cnt[day[j]]>=K) continue;
                    if(deg[day[j]][U[i]]>=dnum&&deg[day[j]][V[i]]>=dnum) continue;
                    deg[day[j]][U[i]]++;
                    deg[day[j]][V[i]]++;
                    NR[i]=day[j]+1;
                    cnt[day[j]]++;
                    cost+=dnum;
                    dsum[day[j]]+=W[i];
                    break;
                }
            }
        }
        bool flag=true;
        vector<UnionFind> uf(D,UnionFind (N));
        rep(i,D) rep(j,M) if(i!=NR[j]-1) uf[i].unite(U[j],V[j]);
        vector<set<int>> vs(D);
        rep(i,D) rep(j,N) vs[i].insert(uf[i].find(j)); 
        vector<int> dcnt(D,0);
        rep(i,M) dcnt[NR[i]-1]++;
        double tot=0.0;
        rep(i,D) {
            if(dcnt[i]>K||(int)vs[i].size()!=1) flag=false; 
            tot+=dsum[i];
        }
        if(!flag) continue;
        if(min_dist>tot/D) {
            //min_cost=cost;
            min_dist=tot/D;
            //cout << "---"  << cost << "---" << tot/D << "---" << endl;
            //rep(i,(int)NR.size()) {
            //    if(i) cout << " ";
            //    cout << NR[i];
            //} cout << endl;
            R=NR;
        }
    }
}

int main() {
    srand(time(NULL));
    input();
    solve();
    output();
    return 0;
}