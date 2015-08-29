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
int main(){
    int testcase = 0;
    cin >> testcase;
    int n=0,m=0;
    int b=-1,e=-1;
    long double muliplex = 1;
    double ans = 0.0;
    for(int tcas=1;tcas<=testcase;tcas++){
    	cin >> n >> m;
    	vector<long double> dim(n);
    	for(int i=0;i<n;i++){
    		cin>>dim[i];
    	}
    	printf("Case #%d:\n", tcas);
    	for(int i=0;i<m;i++){
    		cin >> b >> e;
    		ans =1;
            long double p = 1.0/(double)(e-b+1);
    		for(int j=b;j<=e;j++){
    			ans *=pow(dim[j],p);
    		}
    		//cout << "for test:"<< muliplex << endl;
    		//ans = pow(muliplex,p);
    		printf("%.9lf\n",ans);
    	}

        
        
    }
    return 0;
}
