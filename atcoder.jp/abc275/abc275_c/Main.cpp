#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b))<EPS)

//点
class Point { 
public:
    double x,y;
    Point(double x=0,double y=0): x(x),y(y) {}
    Point operator + (Point p) { return Point(x+p.x,y+p.y); }
    Point operator - (Point p) { return Point(x-p.x,y-p.y); }
    Point operator * (double k) { return Point(x*k,y*k); }
    Point operator / (double k) { return Point(x/k,y/k); }
    bool operator < (const Point &p) const { return x!=p.x ? x<p.x : y<p.y; }
    bool operator == (const Point &p) const { return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS; }
};
//ベクトル
typedef Point Vector; 
//線分
struct Segment { Point p1,p2; }; 
//直線
typedef Segment Line;
//円 
class Circle { 
public:
    Point c; double r;
    Circle(Point c=Point(),double r=0.0): c(c),r(r) {} 
};
//多角形
typedef vector<Point> Polygon; 

//function list
double norm(Point p);
double abs(Point p);
double arg(Point p);
  //内積
double dot(Vector a,Vector b);
  //外積
double cross(Vector a,Vector b);
  //極座標
Vector polar(double r,double theta);
  //射影(1_A)
Point project(Segment s,Point p);
  //線対称の点(1_B)
Point reflect(Segment s,Point p);
  //反時計回り(1_C)
enum {
    COUNTER_CLOCKWISE=1,   //p0,p1,p2が反時計回りになる
    CLOCKWISE=-1,          //p0,p1,p2が時計回りになる
    ONLINE_BACK=2,         //p2,p0,p1の順で同一直線上にある
    ONLINE_FRONT=-2,       //p0,p1,p2の順で同一直線上にある
    ON_SEGMENT=0           //p2が線分p0p1上にある
};
int ccw(Point p0,Point p1,Point p2);
  //直交判定(2_A)
bool isOrthogonal(Vector a,Vector b);
bool isOrthogonal(Point a1,Point a2,Point b1,Point b2);
bool isOrthogonal(Segment s1,Segment s2);
  //平行判定(2_A)
bool isParallel(Vector a,Vector b);
bool isParallel(Point a1,Point a2,Point b1,Point b2);
bool isParallel(Segment s1,Segment s2);
  //交差判定(2_B),(7_A)
bool intersect(Point p1,Point p2,Point p3,Point p4);
bool intersect(Segment s1,Segment s2);
int intersect(Circle c,Line l);
int intersect(Circle c1,Circle c2);
  //交点(2_C),(7_D),(7_E)
Point getCrossPointSS(Segment s1,Segment s2); 
pair<Point,Point> getCrossPointCL(Circle c,Line l);
pair<Point,Point> getCrossPointCC(Circle c1,Circle c2);
  //距離(2_D)
double getDistancePP(Point a,Point b);
double getDistanceLP(Line l,Point p);
double getDistanceSP(Segment s,Point p);
double getDistanceSS(Segment s1,Segment s2);
  //点の内包(3_C)
enum {
    IN=2,   //含まれる
    ON=1,   //線分上
    OUT=0   //含まれない
};
int containP(Polygon g,Point p);
int containC(Circle C,Point p);
  //凸包(4_A)
Polygon convex_full(Polygon P);
//end of list

double norm(Point p) { return p.x*p.x+p.y*p.y; }
double abs(Point p) { return sqrt(norm(p)); } 
double arg(Point p) { return atan2(p.y,p.x); }

double dot(Vector a,Vector b) { return a.x*b.x+a.y*b.y; };
double cross(Vector a,Vector b) { return a.x*b.y-a.y*b.x; }
Vector polar(double r,double theta) { return Point(cos(theta),sin(theta))*r; }

Point project(Segment s,Point p) {
    Vector base=s.p2-s.p1;
    double r=dot(p-s.p1,base)/norm(base);
    return s.p1+base*r;
}
Point reflect(Segment s,Point p) { return p+(project(s,p)-p)*2.0; }
int ccw(Point p0,Point p1,Point p2) {
    Vector a=p1-p0,b=p2-p0;
    if(cross(a,b)>EPS) return COUNTER_CLOCKWISE;
    if(cross(a,b)<-EPS) return CLOCKWISE;
    if(dot(a,b)<-EPS) return ONLINE_BACK;
    if(norm(a)<norm(b)) return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool isOrthogonal(Vector a,Vector b) { return equals(dot(a,b),0.0); }
bool isOrthogonal(Point a1,Point a2,Point b1,Point b2) { return isOrthogonal(a1-a2,b1-b2); }
bool isOrthogonal(Segment s1,Segment s2) { return equals(dot(s1.p2-s1.p1,s2.p2-s2.p1),0.0); }

bool isParallel(Vector a,Vector b) { return equals(cross(a,b),0.0); }
bool isParallel(Point a1,Point a2,Point b1,Point b2) { return isParallel(a1-a2,b1-b2); }
bool isParallel(Segment s1,Segment s2) { return equals(cross(s1.p2-s1.p1,s2.p2-s2.p1),0.0); }

bool intersect(Point p1,Point p2,Point p3,Point p4) { return (ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0&&ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0); }
bool intersect(Segment s1,Segment s2) { return intersect(s1.p1,s1.p2,s2.p1,s2.p2); }
int intersect(Circle c,Line l) {
    double dist=getDistanceLP(l,c.c);
    if(equals(dist,c.r)) return 1;
    if(dist<c.r) return 2;
    return 0;
}
int intersect(Circle c1,Circle c2) {
    double dist=getDistancePP(c1.c,c2.c);
    if(equals(dist,c1.r+c2.r)) return 3;        //外接する
    if(dist>c1.r+c2.r) return 4;                //離れている
    if(equals(dist,abs(c1.r-c2.r))) return 1;   //交わる
    if(dist>abs(c1.r-c2.r)) return 2;           //内接する
    return 0;                                   //内包する
} //辺値は共通接戦の数

Point getCrossPointSS(Segment s1,Segment s2) {
    Vector base=s2.p2-s2.p1;
    double d1=abs(cross(base,s1.p1-s2.p1));
    double d2=abs(cross(base,s1.p2-s2.p1));
    double t=d1/(d1+d2);
    return s1.p1+(s1.p2-s1.p1)*t;
}
pair<Point,Point> getCrossPointCL(Circle c,Line l) {
    assert(intersect(c,l));
    Vector pr=project(l,c.c);
    Vector e=(l.p2-l.p1)/abs(l.p2-l.p1);
    double base=sqrt(c.r*c.r-norm(pr-c.c));
    Point p1=pr-e*base,p2=pr+e*base;
    return p1<p2 ? make_pair(p1,p2):make_pair(p2,p1);
}
pair<Point,Point> getCrossPointCC(Circle c1,Circle c2) {
    assert(intersect(c1,c2));
    double d=getDistancePP(c1.c,c2.c);
    double a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    double t=arg(c2.c-c1.c);
    Point p1=c1.c+polar(c1.r,t+a),p2=c1.c+polar(c1.r,t-a);
    return p1<p2 ? make_pair(p1,p2):make_pair(p2,p1);
}

double getDistancePP(Point a,Point b) { return abs(a-b); }
double getDistanceLP(Line l,Point p) { return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1)); }
double getDistanceSP(Segment s,Point p) {
    if(dot(s.p2-s.p1,p-s.p1)<0.0) return abs(p-s.p1);
    if(dot(s.p1-s.p2,p-s.p2)<0.0) return abs(p-s.p2);
    return getDistanceLP(s,p);
}
double getDistanceSS(Segment s1,Segment s2) {
    if(intersect(s1,s2)) return 0.0;
    return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}

int containP(Polygon g,Point p) {
    bool in=false;
    for(int i=0;i<(int)g.size();i++) {
        Point a=g[i]-p,b=g[(i+1)%(int)g.size()]-p;
        if(abs(cross(a,b))<EPS&&dot(a,b)<EPS) return ON;
        if(a.y>b.y) swap(a,b);
        if(a.y<EPS&&EPS<b.y&&cross(a,b)>EPS) in=!in;
    }
    return in ? IN:OUT;
}
int containC(Circle c,Point p) {
    double dist=getDistancePP(p,c.c);
    if(equals(dist,c.r)) return ON;
    if(dist<c.r) return IN;
    return OUT;
}

Polygon convex_full(Polygon P) {
    int x=P.size();
    if(x<3) return P;
    Polygon up,down;
    sort(P.begin(),P.end());
    up.push_back(P[0]); up.push_back(P[1]);
    down.push_back(P[x-1]); down.push_back(P[x-2]);
    //凸包の上の部分
    for(int i=2;i<x;i++) {
        for(int n=(int)up.size();n>=2&&ccw(up[n-2],up[n-1],P[i])==COUNTER_CLOCKWISE;n--) up.pop_back();
        up.push_back(P[i]);
    }
    //凸包の下の部分
    for(int i=x-3;i>=0;i--) {
        for(int n=(int)down.size();n>=2&&ccw(down[n-2],down[n-1],P[i])==COUNTER_CLOCKWISE;n--) down.pop_back();
        down.push_back(P[i]);
    }
    reverse(down.begin(),down.end());
    for(int i=(int)up.size()-2;i>=1;i--) down.push_back(up[i]);
    int idx=0;
    for(int i=1;i<(int)down.size();i++) {
        if(down[i].y<down[idx].y||(down[i].y==down[idx].y&&down[i].x<down[idx].x)) idx=i;
    }
    //凸多角形の頂点で最も下にあるものの中で最も左にある頂点から順に、反時計周りで頂点の座標を並べる
    Polygon R;
    for(int i=0;i<(int)down.size();i++) R.push_back(down[(idx+i)%(int)down.size()]);
    return R;
} //辺上の点を含まない場合は !=CLOCKWISE と書く

int main() {
    vector<string> s(9);
    rep(i,9) cin >> s[i];
    ll cnt=0;
    for(int i=0;i<81;i++) {
        for(int j=i+1;j<81;j++) {
            for(int k=j+1;k<81;k++) {
                int i1=i/9,j1=i%9;
                int i2=j/9,j2=j%9;
                int i3=k/9,j3=k%9;
                if(s[i1][j1]=='.') continue;
                if(s[i2][j2]=='.') continue;
                if(s[i3][j3]=='.') continue;    
                Point p1,p2,p3,p4;
                p1.x=i1; p1.y=j1;
                p2.x=i2; p2.y=j2;
                p3.x=i3; p3.y=j3;  
                set<Point> se;
                se.insert(p1);
                se.insert(p2);
                se.insert(p3);
                if((int)se.size()!=3) continue;
                double d12=getDistancePP(p1,p2);
                double d23=getDistancePP(p2,p3);
                if(!isOrthogonal(p1,p2,p2,p3)||!equals(d12,d23)) continue; 
                if(isParallel(p1,p2,p2,p3)) continue; 
                p4=reflect({p1,p3},p2);
                if(s[p4.x][p4.y]=='#') cnt++;
            }
        }
    }
    cout << cnt/2 << endl;
    return 0;
}