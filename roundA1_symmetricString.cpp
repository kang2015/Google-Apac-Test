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
long long findPivot(long long k){
    long long num = 0;
    while(k>0){//don't overflow
        k = k>>1;
        num++;
    }
    /*for(int i=1;i<=k;i++){//overflow when k is large
        i = i<< 1;
        cout << i<< endl;
        num++;
    }*/
    return 1L<<(num-1);
}
int main(){
    int testcase = 0;
    cin >> testcase;
    long long k = 0;
    for(int tcas=1;tcas<=testcase;tcas++){
        cin >> k;
        k--;
        if(k<=1){
            printf("Case #%d: %d\n", tcas,0);
            continue;
        }
        long long count = 0;
        long long pivot = 0;
        do{
            if((k&(k+1))==0){
                break;
            }
            pivot = findPivot(k)-1;
            count++;
            k = pivot-(k-pivot);
        }while(k>1);
        
        //cout << count;
        printf("Case #%d: %lld\n", tcas,count%2);
    }
    return 0;
}
