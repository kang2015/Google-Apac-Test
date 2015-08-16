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
#include<string>
using namespace std;
class listNode{
	public:
		string s;
		listNode *next;
		listNode(string input){
			s = input;
			next = NULL;
		}
};
bool isGreater(string a,string b){
	int i1=0,i2=0;
	while(i1<a.length() && i2< b.length()){
		if(a[i1] > b[i2]){
			return true;
		}else if(a[i1] < b[i2]){
			return false;
		}else{
			i1++;i2++;
		}
	}
	if(i1<a.length()){
		return true;
	}else if(i2<b.length()){
		return false;
	}
}
bool isCorrectPos(listNode *p){
	listNode *pp = p->next;
	while(pp){
		if(isGreater(pp->s,p->s)){
			return false;
		}
		pp = pp->next;
	}
	return true;
}
int main(){
	int testcase = 0;
	cin >> testcase;
	int n=0;
	for(int tcas=1;tcas<=testcase;tcas++){
		cin >> n;
		listNode *head = NULL;
		getchar();//skip \n
		for(int i=0;i<n;i++){
			string s;
			getline(cin,s);
			//cout << "first line: "<< s << endl;
			listNode *cur = new listNode(s);
			listNode *next = cur->next;
			cur->next = head;
			head = cur;
		}
		listNode *pp = head;
		int ans = 0;
		while(pp){
			//cout<< pp->s << endl;
			if(!isCorrectPos(pp)){
				ans++;
			}
			pp = pp->next;
		}
		printf("Case #%d: %d\n", tcas,ans);
		
	}
	return 0;
}
