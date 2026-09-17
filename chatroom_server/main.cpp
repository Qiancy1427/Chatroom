//Server
// Created by qianchengyi on 2025/5/8.
//
#include "Connecting.h"
#include <thread>
#include <winsock2.h>
using namespace std;
thread th[16];
char cinfo[1000];
int cli_cnt;
void *mlisten(int th_num){
    cout << sinfo[th_num].fd << "\n";   //11
    int recv_len;
    char recv_buff[1000];
    while(true){
        recv_len = recv(sinfo[th_num].fd, cinfo, 255, 0);
        if(recv_len < 0){
            cli_cnt--;
            sinfo[th_num].fd = -1;
            break;
        }
        cout << cinfo << "\n";
//        cinfo.push(recv_buff);
//        memset(recv_buff, 0, sizeof(recv_buff));
    }
}
void *mbroadcast(){
    while(true){
        if(cinfo[0] <= 0)    continue;
//        if(cinfo.empty())   continue;
        for(int i = 0; i < 20; i++){
            if(sinfo[i].fd == -1)   continue;
            int tmp = send(sinfo[i].fd, cinfo, sizeof(cinfo), 0);
            cout << tmp << " " << cinfo << "\n";
            if(tmp < 0) cout << "send err\n";
        }
        memset(cinfo, 0, sizeof(cinfo));
//        cinfo.pop();
    }
}
int main(){
    WORD socketVersion=MAKEWORD(2,2);
    WSADATA wd;
    if(WSAStartup(socketVersion,&wd)!=0)    return 0;
    sserver = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sserver == -1){
        cout<<"SOCKET Failed\n";    //for test
        return -1;
    }
    if(!mbind()){
        cout<<"Bind Failed\n";  //for test
        return -1;
    }
    cout << 1 << "\n";  //1
    init_sockinfo();
    th[0] = thread(mbroadcast);
    th[0].detach();
    while(true){
        int tmp;
        sockaddr_in addr;
        for(tmp = 0; tmp < 20; tmp++){
            if(sinfo[tmp].fd == -1) break;
        }
        int addrlen = sizeof(sockaddr_in);
        SOCKET cfd = accept(sserver, (sockaddr*)&sinfo[tmp].cliaddr, &addrlen);
        if(cfd == -1){
            cout << "Accept Failed\n";
            continue;
        }
        sinfo[tmp].fd = cfd;
        cli_cnt++;
        th[tmp + 1] = thread(mlisten, tmp);
        th[tmp + 1].detach();
    }
    return 0;
}