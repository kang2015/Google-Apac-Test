//my ans
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include<memory>
#include<map>
#include<queue>
#include <sstream>
#include <set>
#include <list>
using namespace std;
class Node{
public:
    int vertex;
    int dist;
    int idx;
    
    Node(int _vertex, int _dist, int _idx){
        vertex = _vertex;
        dist = _dist;
        idx = _idx;
    }
};
void dijkstra(vector<list<Node> > &graph,int i,vector<bool> &edge,int num){
    vector<bool> vis(num,false);
    vector<long long> dist(num,INT64_MAX);
    dist[i] = 0;
    for(int i=0;i<num;i++){
        int mi = -1;
        for(int j=0;j<num;j++){
            if(!vis[j]){
                if(mi == -1 || dist[j] < dist[mi]){
                    mi=j;
                }
            }
        }
        vis[mi] = true;
        //cout<< "min dist is : "<< dist[mi] << endl;
        for(auto it = graph[mi].begin();it!=graph[mi].end();it++){
            if(dist[it->vertex] > dist[mi] + it->dist){
                dist[it->vertex] = dist[mi] + it->dist;
            }
        }
        
    }
    for(int i=0;i<num;i++){
        for(auto it = graph[i].begin();it!=graph[i].end();it++){
            if(dist[it->vertex] == dist[i] + it->dist){
                edge[it->idx] = true;
            }
        }
    }
    
}
int main(){
    int testcase = 0;
    cin >> testcase;
    for(int tcas=1;tcas<=testcase;tcas++){
        int n=0,m=0;
        cin >> n >> m;
        vector<list<Node> > graph(n);
        for(int i=0;i<m;i++){
            int v1,v2,dist;
            cin >> v1 >> v2 >> dist;
            graph[v1].push_back(Node(v2,dist,i));
            graph[v2].push_back(Node(v1,dist,i));
        }
        vector<bool> edge(m,false);
        for(int i=0;i<n;i++)
            dijkstra(graph,i,edge,n);
        printf("Case #%d: \n", tcas);
        for(int i=0;i<m;i++){
            //cout << edge[i] << endl;
            if(!edge[i]){
                cout << i << endl;
            }
        }
        
    }
    return 0;
}

//end of my ans

// @author cebrusfs
// headers {{{
#include<bits/stdc++.h>
using namespace std;
// }}}
// macros {{{
#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(x) (sort(ALL(x)), ((x).erase(unique(ALL(x)), (x).end())))
#define MS(x, v) std::fill(ALL(x), (v));

#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)

#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> PII;
#define MP make_pair
#define F first
#define S second

typedef vector<int> VI;
#define PB push_back
#define PF push_front

#define PPB pop_back
#define PPF pop_front

#define runtime() ((double)clock() / CLOCKS_PER_SEC)

const double eps = 1e-7;

// C++11
#if __cplusplus >= 201103L
#define MT make_tuple
typedef tuple<int, int> TII;

// dump {{{
template<typename T>
void _dump(const char* s, T&& head) {
    cerr<< s << "=" << head << endl;
}
 
template<typename T, typename... Args>
void _dump(const char* s, T&& head, Args&&... tail) {
    int c = 0;
    while (*s!=',' || c!=0) {
        if (*s=='(' || *s=='[' || *s=='{') c++;
        if (*s==')' || *s==']' || *s=='}') c--;
        cerr << *s++;
    }
    cerr << "=" << head << ", ";
    _dump(s+1, tail...);
}
 
#ifdef FISH
#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0);
#else
#define dump(...) ;
#endif
 
template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}
 
template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
// }}}
#endif
// }}}

#define MAX 10005
#define INF 1e18

bool used[MAX];

long long dis[MAX];
bool vis[MAX];

struct edge
{
    int b, c;
    int idx;

    edge(int _b, int _c, int _idx)
    {
        b = _b, c = _c, idx = _idx;
    }
};

vector<edge> e[MAX];

void dijkstra(int n, int st)
{
    for (int i = 0; i < n; ++i)
        dis[i] = INF, vis[i] = false;

    dis[st] = 0;

    for (int k = 0; k < n; ++k)
    {
        int mi = -1;
        for (int i = 0; i < n; ++i)
            if (not vis[i] and (mi == -1 or dis[mi] > dis[i]))
                mi = i;

        assert(mi != -1);

        vis[mi] = true;

        for (const auto& eg : e[mi])
        {
            if (dis[eg.b] > dis[mi] + eg.c)
                dis[eg.b] = dis[mi] + eg.c;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (const auto& eg : e[i])
        {
            if (dis[eg.b] == dis[i] + eg.c)
                used[eg.idx] = true;
        }
    }

}

void solve(int caseid)
{
    fprintf(stderr, "solve at Case %d ... \n", caseid);
    printf("Case #%d:\n", caseid);

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i)
        e[i].clear();

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        used[i] = false;
        e[a].PB(edge(b, c, i));
        e[b].PB(edge(a, c, i));
    }

    for (int i = 0; i < n; ++i)
        dijkstra(n, i);

    for (int i = 0; i < m; ++i)
        if (not used[i])
            printf("%d\n", i);


}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        solve(i);
}

