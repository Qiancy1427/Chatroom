#include <bits/stdc++.h>
#include <winsock2.h>
#include <pthread.h>
#include "Render.h"
#include "Connecting.h"
using namespace std;
string password;
int indexes[15];
pthread_t threads[15];
int main() {
    WORD socketVersion=MAKEWORD(2,2);
    WSADATA wd;
    if(WSAStartup(socketVersion,&wd)!=0)    return 0;
    cout<<"Welcome to chat room. Please login first."<<"\n";
    cin>>userid>>password;
    readdata=userid;
    sclient=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    bool iscnt=cnt();
    if(!iscnt){
        cout<<"Connection Failed"<<"\n";
        system("pause");
    }
    else    cout<<"Connection Succeeded"<<"\n"; //for test
    system("pause");    //for test
    int rc=pthread_create(&threads[1],NULL,msend,&(indexes[1]));
    if(rc!=0){
        cout<<"failed to send \n";
        exit(-1);
    }
    rc=pthread_create(&threads[2],NULL,mrec,(void *)&(indexes[2]));
    if(rc!=0){
        cout<<"falied to recieve \n";
        exit(-1);
    }
    for(int i=1;i<=sum;i++){
        cout<<history[i]<<"\n";
    }
    cout<<readdata;
    WSACleanup();
    return 0;
}
