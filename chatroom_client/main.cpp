//Client
#include <thread>
#include "Render.h"
#include "Connecting.h"
using namespace std;
int indexes[15];
thread th[15];
void *th_1(){
    while(true){
        for(int i = 0; i < useridlen; i++)  msg[i] = userid[i];
        msglength = useridlen;
        msg[msglength++] = ':';
        int isread = readkb();
        if(isread == -1)    break;
        msend(msg);
        memset(msg, 0, sizeof(msg));
//        msglength = 0;
    }
}
void *th_2(){
    while(true){
        mrec();
        rendhistory(sum_mes);
    }
}
int main() {
    WORD socketVersion=MAKEWORD(2,2);
    WSADATA wd;
    if(WSAStartup(socketVersion,&wd)!=0)    return 0;
    initializerend();

    outtextxy(40, 465, "USERID:");
    useridlen = readkb();
    for(int i = 0; i < useridlen; i++)  userid[i] = msg[i];
    memset(msg, 0, sizeof(msg));

    sclient=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(sclient == -1){
        cout<<"SOCKET Failed"<<"\n";
        return -1;
    }
    bool iscnt=cnt();
    if(!iscnt){
        cout<<"Connection Failed\n";
        return -1;
    }
    else    cout<<"Connection Succeeded\n"; //for test
    th[0] = thread(th_1);
    th[1] = thread(th_2);
    th[1].detach();
    th[0].join();

    WSACleanup();
    return 0;
}
