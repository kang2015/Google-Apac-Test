//my ans with priority queue
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
    int dist[24];
    
    
    Node(int _vertex, int _dist[]){
        vertex = _vertex;
        for(int i=0;i<24;i++)
            dist[i]=_dist[i];
        
    }
};
int dijkstra(vector<list<Node> > &graph,int source,int sink,int num,int time){
    vector<bool> vis(num,false);
    vector<int> dist(num,INT_MAX);
    vector<int> times(num,-1);
    dist[source] = 0;
    times[source] = time;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
    q.push(make_pair(0,0));
    while(!q.empty()){
        pair<int,int> cur=q.top();q.pop();
        //cout << "min dist node is:"<< cur.first <<" " << q.size() <<endl;
        int mi = cur.second;
        if(dist[mi] == INT_MAX){
            break;
        }
        if(vis[mi]){
            continue;
        }
        vis[mi] = true;
        if(mi == sink){
            return dist[mi];
        }
        //int nextTime = (time + dist[mi])%24;
        //cout<< "min dist is : "<< dist[mi] << endl;
        for(auto it = graph[mi].begin();it!=graph[mi].end();it++){
            if(!vis[it->vertex] && dist[it->vertex] > dist[mi] + it->dist[times[mi]]){
                dist[it->vertex] = dist[mi] + it->dist[times[mi]];
                times[it->vertex] = (times[mi] + it->dist[times[mi]])%24;
                q.push(make_pair(dist[it->vertex],it->vertex));
                //cout << "push" << it->vertex << " "<< dist[it->vertex] << endl;
            }
        }
        //time = nextTime;
    }
    return -1;
    
}
int main(){
    int testcase = 0;
    cin >> testcase;
    for(int tcas=1;tcas<=testcase;tcas++){
        int n=0,m=0,k=0;
        cin >> n >> m >> k;
        vector<list<Node> > graph(n);
        for(int i=0;i<m;i++){
            int v1,v2;
            int dist[24]={0};
            cin >> v1 >> v2;
            int tmp =0;
            for(int j=0;j<24;j++){
                cin >> tmp;
                dist[j]=tmp;
            }
            graph[v1-1].push_back(Node(v2-1,dist));
            graph[v2-1].push_back(Node(v1-1,dist));
        }
        printf("Case #%d:", tcas);
        for(int i=0;i<k;i++){
            int sink=0,time =0;
            cin>>sink>>time;
            cout << " "<< dijkstra(graph,0,sink-1,n,time) ;
            
        }
        cout << endl;
        
        
    }
    return 0;
}

//end of my ans





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
    int dist[24];
    
    
    Node(int _vertex, int _dist[]){
        vertex = _vertex;
        for(int i=0;i<24;i++)
            dist[i]=_dist[i];
        
    }
};
int dijkstra(vector<list<Node> > &graph,int source,int sink,int num,int time){
    vector<bool> vis(num,false);
    vector<int> dist(num,INT_MAX);
    vector<int> times(num,-1);
    dist[source] = 0;
    times[source] = time;
    for(int i=0;i<num;i++){
        int mi = -1;
        for(int j=0;j<num;j++){
            if(!vis[j]){
                if(mi == -1 || dist[j] < dist[mi]){
                    mi=j;
                }
            }
        }
        if(dist[mi] == INT_MAX){
            break;
        }
        vis[mi] = true;
        if(mi == sink){
            return dist[mi];
        }
        //int nextTime = (time + dist[mi])%24;
        //cout<< "min dist is : "<< dist[mi] << endl;
        for(auto it = graph[mi].begin();it!=graph[mi].end();it++){
            if(dist[it->vertex] > dist[mi] + it->dist[times[mi]]){
                dist[it->vertex] = dist[mi] + it->dist[times[mi]];
                times[it->vertex] = (times[mi] + it->dist[times[mi]])%24;
            }
        }
        //time = nextTime;
    }
    return -1;
    
}
int main(){
    int testcase = 0;
    cin >> testcase;
    for(int tcas=1;tcas<=testcase;tcas++){
        int n=0,m=0,k=0;
        cin >> n >> m >> k;
        vector<list<Node> > graph(n);
        for(int i=0;i<m;i++){
            int v1,v2;
            int dist[24]={0};
            cin >> v1 >> v2;
            int tmp =0;
            for(int j=0;j<24;j++){
                cin >> tmp;
                dist[j]=tmp;
            }
            graph[v1-1].push_back(Node(v2-1,dist));
            graph[v2-1].push_back(Node(v1-1,dist));
        }
        printf("Case #%d:", tcas);
        for(int i=0;i<k;i++){
            int sink=0,time =0;
            cin>>sink>>time;
            cout << " "<< dijkstra(graph,0,sink-1,n,time) ;
            
        }
        cout << endl;
        
        
    }
    return 0;
}
//end of my ans with priority queue

#include <cstdio>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <deque>
#include <thread>

using namespace std;

int dp[600][24];
int v[600][24],vcnt;
int cost[2000][24];
int road[2000][2];
vector<vector<int>> graph;

int main()
{
	int T;
	scanf("%d",&T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		fprintf(stderr, "Case #%d processing\n", testcase);
		graph.clear();
		
		printf("Case #%d:",testcase);
		int n,m,K;
		scanf("%d%d%d",&n,&m,&K);
		graph.resize(n);
		for (int i = 0; i < m; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			graph[x].push_back(i);
			graph[y].push_back(i);
			road[i][0] = x;
			road[i][1] = y;
			for (int j = 0; j < 24; j++) {
				scanf("%d",&cost[i][j]);
			}
		}
		for (int i = 0; i < K; i++) {
			int D, S;
			scanf("%d%d",&D,&S);
			D--;
			memset(dp,-1,sizeof(dp));
			priority_queue<pair<int,pair<int,int>>> q;
			++vcnt;
			dp[0][S] = 0;
			q.push(make_pair(0,make_pair(0,S)));
			int ans = -1;
			while(!q.empty()) {
				auto pos = q.top().second; q.pop();
				if (pos.first == D) {
					ans = dp[pos.first][pos.second];
					break;
				}
				if (v[pos.first][pos.second] == vcnt) continue;
				v[pos.first][pos.second] = vcnt;
				for (auto edgeindex : graph[pos.first]) {
					int next = road[edgeindex][0] ^ road[edgeindex][1] ^ pos.first;
					int cost = ::cost[edgeindex][pos.second];
					int ntime = (cost + pos.second)%24;

					if (dp[next][ntime] == -1 || dp[next][ntime] > dp[pos.first][pos.second] + cost)
					{
						dp[next][ntime] = dp[pos.first][pos.second] + cost;
						q.push(make_pair(-dp[next][ntime], make_pair(next,ntime)));
					}
				}
			}
			printf(" %d", ans);
		}
		puts("");
	}
	return 0;
}
