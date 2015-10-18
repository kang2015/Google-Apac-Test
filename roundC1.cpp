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
#include <thread>
#include <iostream>

using namespace std;
long long p,n,pm;
class scorelist{
	public:
	multiset<long long> score;
	long long minScore;
	long long num;
	void addScore(long long s){
		
		/*if(num < m){
			score.insert(s);
			num++;
		}else{
			if(s > minScore){
				score.erase(score.begin());
				score.insert(s);
			}
		}*/
		score.insert(s);
		num++;
		
	}
	scorelist(){
		minScore=0;
		num=0;
	}
};
int main()
{
	int T;
	scanf("%d",&T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		fprintf(stderr, "Case #%d processing\n", testcase);
		printf("Case #%d:\n",testcase);
		cin >> p;
		vector<long long> scores(p,0);
		map<string,scorelist> m;
		for(long long i=0;i<p;i++)
			cin >> scores[i];
		cin >> n;
		for(long long i=0;i<n;i++){
			long long w=0;
			cin >> w;
			for(long long j=0;j<p;j++){
				string name;
				cin >> name;
				map<string,scorelist>::iterator it=m.find(name);
				if(it==m.end()){
					scorelist tmp;
					m.insert(make_pair(name,tmp)) ;
				}
				it=m.find(name);
				it->second.addScore(w*scores[j]);
			}
		}
		cin >> pm;
		map<long long,vector<string>> rank;
		for(map<string,scorelist>::iterator it=m.begin();it!=m.end();it++){
			//cout << it->first << " ";
			long long ans=0;
			long long i=0;
			for(set<long long>::reverse_iterator it1=it->second.score.rbegin();it1!=it->second.score.rend()&&i<pm;it1++){
				//cout << *it1 << " ";
				ans += *it1;
				i++;
			}
			//cout << endl;
			//cout << ans << endl;
			
			if(rank.find(ans) == rank.end()){
				vector<string> tmp;
				rank.insert(make_pair(ans,tmp));
			}
			map<long long,vector<string>>::iterator it2 = rank.find(ans);
			it2->second.push_back(it->first);
			
		}
		long long cur=1;
		for(map<long long,vector<string>>::reverse_iterator it3 = rank.rbegin();it3!=rank.rend();it3++){
			for(long long i=0;i<it3->second.size();i++){
				cout << cur << ": "<< it3->second[i] << endl;
			}
			cur += it3->second.size();
		}
		
	}
	return 0;
}
