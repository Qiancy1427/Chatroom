//
// Created by qianchengyi on 2025/5/8.
//
#include <bits/stdc++.h>
using namespace std;
extern int sum;
extern string history, readdata;
void rerend(){
    system("cls");
    for(int i=1;i<=sum;i++){
        cout<<history[i]<<"\n";
    }
    cout<<readdata;
}
