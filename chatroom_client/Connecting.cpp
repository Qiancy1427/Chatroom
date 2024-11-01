//
// Created by qianchengyi on 2024/10/26.
//
#include<bits/stdc++.h>
#include<winsock2.h>
using namespace std;
extern const char *serid;
extern SOCKET sclient;
extern string userid,readdata,history[10005];
extern bool flg;
extern int sum;
bool cnt(){
    if(sclient==INVALID_SOCKET) return false;
    sockaddr_in seraddr;
    seraddr.sin_family=AF_INET;
    seraddr.sin_port=htons(8888);
    seraddr.sin_addr.S_un.S_addr=inet_addr(serid);
    if(connect(sclient,(sockaddr *)&seraddr,sizeof(seraddr))==SOCKET_ERROR){
        closesocket(sclient);
        return false;
    }
    return true;
}
void *msend(void *id){
    flg=true;
    readdata+=getchar();
    if(readdata[readdata.size()-1]!='\n'){
        pthread_exit(NULL);
    }
    const char *senddata;
    senddata=readdata.c_str();
    int x=send(sclient,senddata,strlen(senddata),0);
    cout<<x;    //for test
    flg=false;
    pthread_exit(NULL);
}
void *mrec(void *id){
    char recdata[255];
    int ret=recv(sclient,recdata,255,0);
    if(ret>0){
        recdata[ret]=0x00;
    }
    string ss(recdata);
    history[++sum]=ss;
    pthread_exit(NULL);
}