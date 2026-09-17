//Client
#include <thread>
#include "Render.h"
#include "Connecting.h"
using namespace std;
int indexes[15];
thread th[15];
void *th_1(){
    while(true){
        char senddata[1000];
        cin.getline(senddata, sizeof(senddata));
//        for(int i = 0; i<1000; i++){
//            senddata[i] = readkey();
//            if(senddata[i] == 13)   break;
//        }
        msend(senddata);
    }
}
void *th_2(){
    for(int i = 1; i <= 5; i++ ){
        mrec();
        cout << history[sum_mes] << " main\n";
        //rendhistory(history);
    }
}
int main() {
    WORD socketVersion=MAKEWORD(2,2);
    WSADATA wd;
    if(WSAStartup(socketVersion,&wd)!=0)    return 0;
    //initializerend();

    //wstring test = paste();
//    for(int i = 0; i < test.size(); i++){
//        history[0][i] = test[i];
//    }

    /*for(int i = 0; i < 100; i++){
        for(int j = 0; j < 1000; j++){
            history[i][j] = readkey();
            if(history[i][j] == 13)   break;
        }
        rendhistory(i);
    }*/

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
    th[0].detach();
    th[1].join();

    WSACleanup();
    return 0;
}
