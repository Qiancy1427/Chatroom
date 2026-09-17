//
// Created by qianchengyi on 2025/7/25.
//

#ifndef CHATROOM_SERVER_CONNECTING_H
#define CHATROOM_SERVER_CONNECTING_H

#include <bits/stdc++.h>
#include <winsock2.h>
using namespace std;
SOCKET sserver;
struct sockinfo{
    sockaddr_in cliaddr;
    SOCKET fd;
}sinfo[20];

void init_sockinfo(){
    for(int i = 0; i < 20; i++){
        sinfo[i].fd = -1;
    }
    return;
}

bool mbind(){
    if(sserver == INVALID_SOCKET)   return false;
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.S_un.S_addr = INADDR_ANY;
    int ret = bind(sserver, (sockaddr*)&addr, sizeof(addr));
    if(ret == -1)   return false;
    ret = listen(sserver, 20);
    if(ret == -1)   return false;
    return true;
}

#endif
