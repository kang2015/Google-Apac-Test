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
using namespace std;
bool dfs(int i, vector<vector<int> > &edges, set<int> &s1, set<int> &s2){
	if(i == edges.size()){
		return true;
	}
	bool include1 = false,include2 = false;
	for(int j=0;j<edges[i].size();j++){
		if(s1.count(edges[i][j])){
			include1 = true;
		}
		if(s2.count(edges[i][j])){
			include2 = true;
		}
	}
	if(!include1){
		s1.insert(i);
		if(dfs(i+1,edges,s1,s2)){
			return true;
		}
		s1.erase(i);
	}
	if(!include2){
		s2.insert(i);
		if(dfs(i+1,edges,s1,s2)){
			return true;
		}
		s2.erase(i);
	}
	return false;
}
int main(){
	int testcase = 0;
	cin >> testcase;
	int n = 0;
	for(int tcas=1;tcas<=testcase;tcas++){
		cin >> n;
		vector<string> st;
		vector<vector<int> > edges;
		for(int i=0;i<n;i++){
			string u1,u2;
			cin >> u1 >> u2;
			int i1=-1,i2=-1;
			for(int j=0;j<st.size();j++){
				if(st[j] == u1){
					i1=j;
				}
				if(st[j] == u2){
					i2=j;
				}
			}
			if(i1 == -1){
				i1 = st.size();
				st.push_back(u1);
			}
			if(i2 == -1){
				i2 = st.size();
				st.push_back(u2);
			}
			edges.resize(st.size());
			edges[i1].push_back(i2);
			edges[i2].push_back(i1);
		}
		/*  for(int i=0;i<edges.size();i++){
			cout<< i << " : ";
			for(int j=0;j<edges[i].size();j++){
				cout << edges[i][j] <<" ";
			}
			cout << endl;
		}  */
		set<int> s1,s2;
		bool ans = dfs(0,edges,s1,s2);
		if(ans){
			printf("Case #%d: Yes\n", tcas);
		}else{
			printf("Case #%d: No\n", tcas);
		}
		
	}
	return 0;
}
