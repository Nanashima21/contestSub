#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

struct DAG {
private:
    struct Edge { int to; };
    std::vector<std::vector<Edge>> graph;
    bool is_dag = false;
    std::vector<int> sorted;
    int V;
public:
    DAG(int v) {
        assert(v>0);
        V=v;
        graph.resize(v);
    }
    void add_edge(int from,int to) {
       graph[from].push_back({to});
    }
    std::vector<int> topological_sort() {
        //std::stack<int> sta;
        std::priority_queue<int,vector<int>,greater<int>> sta;
        std::vector<int> in(V,0);
        int used_cnt = 0;
        for(int i=0;i<V;i++) for(Edge e:graph[i]) in[e.to]++;
        for (int i=0;i<V;i++) if (in[i]==0) {
            sta.push(i);
            used_cnt++;
        }
        while (!sta.empty()) {
            int p=sta.top(); sta.pop();
            sorted.push_back(p);
            for (Edge e:graph[p]) {
                int v=e.to;
                in[v]--;
                if(in[v]==0) {
                    sta.push(v);
                    used_cnt++;
                }
            }
        }
        if(used_cnt==V) return sorted;
        else return std::vector<int>(0);
    }
    vector<Edge>& operator[](int x) { return graph[x]; }
    //DAG dag(n)
};

int main() {
    int n,m;
    cin >> n >> m;
    DAG dag(n);
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        dag.add_edge(a,b);
    }
    vector<int> v=dag.topological_sort();
    if((int)v.size()==0) cout << -1 << endl;
    else {
        rep(i,(int)v.size()) {
            if(i) cout << " ";
            cout << v[i]+1;
        } cout << endl;
    }
    return 0;
}