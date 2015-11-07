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
//#include <multiset>
#include <deque>
#include <iostream>

using namespace std;

int main()
{
	int T,n,p;
	scanf("%d",&T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		fprintf(stderr, "Case #%d processing\n", testcase);
		printf("Case #%d: ",testcase);
		cin >> n;
		vector<pair<int,int> > gap(n,make_pair(0,0));
		for(int i=0;i<n;i++){
			cin >> gap[i].first;
			cin >> gap[i].second;
		}
		cin >> p;
		vector<int> point(p,0);
		vector<int> ans(p,0);
		for(int i=0;i<p;i++)
			cin >> point[i];
		for(int i=0;i<n;i++)
			for(int j=0;j<p;j++){
				if(gap[i].first <= point[j] && gap[i].second >= point[j]){
					ans[j]++;
				}
			}
		for(int i=0;i<p;i++)
			cout << ans[i] << " ";
		cout << endl;
		
	}
	return 0;
}
