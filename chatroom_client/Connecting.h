//
// Created by qianchengyi on 2024/10/26.
//

#ifndef CHATROOM_CLIENT_CONNECTING
#define CHATROOM_CLIENT_CONNECTING

#include<bits/stdc++.h>
#include<winsock2.h>
#include<winsock.h>
using namespace std;
const char *serid="10.34.216.125";
int sum_mes;
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
    cout << x << "\n";    //for test
}
void mrec(){
    char recdata[1000];
    int ret=recv(sclient,recdata,255,0);
    cout << ret << " "<< recdata << "\n";
    sum_mes++;
    for(int i = 0; i < 1000; i++){
        history[sum_mes][i] = recdata[i];
    }
}

#endif