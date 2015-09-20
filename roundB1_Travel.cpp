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
