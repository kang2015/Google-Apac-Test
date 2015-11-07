/**
input
2
2
3 4
1 2 

3
1 2 9 
5 3 8 
4 6 7

output
Case #1: 1 2
Case #2: 6 4
*/

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

/*ans1
int s;
pair<int,int> ans;
int dfs(int i,int j,
vector<vector<bool> > &vis,vector<vector<int> > &square){
	int cur;
	vis[i][j] = true;
	if(i>0 && square[i-1][j] == square[i][j]+1){
		cur = 1+ dfs(i-1,j,vis,square);
	}else if(j>0 && square[i][j-1] == square[i][j] + 1){
		cur = 1 + dfs(i,j-1,vis,square);
	}else if(i<s-1 && square[i+1][j] == square[i][j] + 1){
		cur = 1+ dfs(i+1,j,vis,square);
	}else if(j<s-1 && square[i][j+1] == square[i][j] + 1){
		cur = 1+ dfs(i,j+1,vis,square);
	}else{
		cur = 1;
	}
	if(cur > ans.second){
		ans.first = square[i][j];
		ans.second = cur;
	}else if(cur == ans.second && square[i][j] < ans.first){
		ans.first = square[i][j];
	}
	//cout << i << " " << j << " " << square[i][j] <<  " "<< cur << endl; 
	return cur;
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		fprintf(stderr, "Case #%d processing\n", testcase);
		printf("Case #%d: ",testcase);
		cin >> s;
		vector<vector<int> > square(s,vector<int>(s,-1));
		vector<vector<bool> > vis(s,vector<bool>(s,false));
		for(int i=0;i<s;i++)
		{
			for(int j=0;j<s;j++){
				cin>>square[i][j];
				//cout << square[i][j] << " ";
			}
			//cout << endl;
		}
				
		ans=make_pair(-1,0);// <pos,step>
		for(int i=0;i<s;i++)
			for(int j=0;j<s;j++)
				if(!vis[i][j]){
					dfs(i,j,vis,square);
				}
		
		cout << ans.first << " " << ans.second << endl;		
		
	}
	return 0;
}*/
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int main()
{
	int T,s;
	scanf("%d",&T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		fprintf(stderr, "Case #%d processing\n", testcase);
		printf("Case #%d: ",testcase);
		cin >> s;
		vector<int> dp(s*s+1,0);
		vector<vector<int> > square(s,vector<int>(s,0));
		for(int i=0;i<s;i++)
			for(int j=0;j<s;j++)
				cin >> square[i][j];
		for(int i=0;i<s;i++)
			for(int j=0;j<s;j++)
				if((i>0 && square[i-1][j] == square[i][j]+1)
					||(j>0 && square[i][j-1] == square[i][j]+1)
					||(i<s-1 && square[i+1][j] == square[i][j]+1)
					||(j<s-1 && square[i][j+1] == square[i][j]+1)){
						dp[square[i][j]]=1;
					}else{
						dp[square[i][j]]=0;
					}
		dp[s*s]=1;
		int ans1=-1,ans2=0;
		for(int i=s*s-1;i>=1;i--){
			if(dp[i]==1){
				dp[i] = dp[i+1]+1;
			}else{
				dp[i] = 1;
			}
			if(dp[i] >= ans2){
				ans2 = dp[i];
				ans1 = i;
			}
		}
		cout << ans1 << " " << ans2 << endl;
				
		
	}
	return 0;
}
