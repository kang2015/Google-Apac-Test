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

int main()
{
	int T;
	scanf("%d",&T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		fprintf(stderr, "Case #%d processing\n", testcase);
		printf("Case #%d: ",testcase);
		int n,k,c;
		long long x;
		cin>> n>> k >> c >> x;
		vector<long long> a(n,0);
		vector<long long> b(n,0);
		for(int i=0;i<n;i++){
			cin >> a[i];
			a[i] = a[i]*(i+1)%x;
		}
			
		for(int i=0;i<n;i++){
			cin >> b[i];
			b[i] = b[i]*(i+1)%x;
		}
			
		long long ans =0;
		for(int i=0;i<=n-k;i++){
			for(int j=0;j<=n-k;j++){
				long long maxV = -1;
				for(int l=i;l<i+k;l++){
					for(int m=j;m<j+k;m++){
						long long cur = (a[l] + b[m]+c%x)%x;
						//cout << cur << " ";
						maxV = max(maxV,cur);	
					}
					//cout << endl;
				}
				//cout << maxV << endl;
				ans += maxV%x;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
