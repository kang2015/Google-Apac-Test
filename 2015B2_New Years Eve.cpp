//
//  B2_2015.cpp
//  xcode-test
//
//  Created by 康炎丽 on 15/9/6.
//  Copyright (c) 2015年 康炎丽. All rights reserved.
//

#include <stdio.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
double run(){
    int b,l,n;
    cin >> b >> l >> n;
    int num = (l+1)*(l+2)/2+1;
    vector<double> cur(num,0);
    vector<double> next(num,0);
    next[1] = b*750;
    for(int i=1;i<=l;i++){
        int id=1;
        for(int idx=1;idx<=(i)*(i+1)/2;idx++)cur[idx]=next[idx];
        for(int idx=1;idx<=(i)*(i+1)/2;idx++)next[idx] = 0;
        for(int row=1;row<=i;row++){
            for(int col=1;col<=row;col++){
                if(cur[id] > 250){
                    double tmp = (cur[id]-250)/3;
                    //cout << "tmp: "<< tmp << endl;
                    next[id] += tmp;
                    next[id+row] += tmp;
                    next[id+row+1] += tmp;
                    cur[id]=250;
                }
                id++;
            }
        }
        
    }
    return cur[n];
}
int main() {
    int tc = 0;
    cin >> tc;
    for(int i=1;i<=tc;i++){
        cout <<"Case #"<<i<<": ";
        printf("%.7lf\n",run());
    }
    return 0;
}
