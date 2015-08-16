#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <queue>
#include <math.h>
#include <bitset>
#include <climits>
#include <sstream>
#include <unordered_map>
#define MP make_pair

using namespace std;
typedef long long LL;
typedef unsigned int uint;
typedef pair<int,int> pii;
const double pi = atan (1.0) * 4;
double V, D;

int main (){
	int T; scanf ("%d",&T);
	for (int cas=1;cas<=T;cas++){
		cin >> V >> D;
		double tmp = D * 9.8 / (V * V);
		double al = asin (tmp) / pi * 180;
		double ans = al / 2;
		printf ("Case #%d: %.6f\n",cas,ans);
	}
	return 0;
}
