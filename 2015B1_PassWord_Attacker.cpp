//
//  2015RoundB1.cpp
//  xcode-test
//
//  Created by 康炎丽 on 15/9/5.
//  Copyright (c) 2015年 康炎丽. All rights reserved.
//
//using "combination"（排列组合） and "inclusion-exclusion principle"(容斥原理)
#include<vector>
#include<iostream>
#include<math.h>
using namespace std;
#define MAX 101
#define MOD 1000000007
long long run(vector<vector<long long> > &combine){
    int m=0,n=0;
    cin>>m>>n;
    long long ans = 0;
    bool isNegative = false;
    for(int i=m;i>0;i--){
        long long tmp = combine[m][i];
        tmp = isNegative?(MOD-tmp):tmp;
        tmp %= MOD;
        for(int j=0;j<n;j++){
            tmp = tmp*i%MOD;
        }
        ans = (ans+tmp)%MOD;
        isNegative = !isNegative;
    }
    return ans;
    
}
int main(){
    int testcases=0;
    cin >> testcases;
    vector<vector<long long> > combine(MAX,vector<long long>(MAX,-1));
    for(int i=0;i<MAX;i++){
        combine[i][0]=1;
        combine[i][i]=1;
        for(int j=1;j<i;j++){
            combine[i][j] = (combine[i-1][j-1]+combine[i-1][j])%MOD;
        }
    }
    for(int i=1;i<=testcases;i++){
        cout << "Case #"<<i<<": "<<run(combine)<<endl;
    }
}
