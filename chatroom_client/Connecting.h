//
// Created by qianchengyi on 2024/10/26.
//
#include<bits/stdc++.h>
#include<winsock2.h>
#include<winsock.h>
using namespace std;
const char *serid="110.242.68.3";
SOCKET sclient;
string userid, password;
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
void msend(char *senddata){
    int x=send(sclient,senddata,strlen(senddata),0);
    cout<<x;    //for test
    return;
}
void mrec(char *recdata){
    int ret=recv(sclient,recdata,255,0);
    return;
}