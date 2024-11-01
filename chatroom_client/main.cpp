#include <bits/stdc++.h>
#include <winsock2.h>
#include <pthread.h>
using namespace std;
const char *serid="110.242.68.3";
string userid,password,history[10005];
SOCKET sclient;
bool flg;
bool cnt();
void *msend(void *id),*mrec(void *id);
int sum,indexes[15];
pthread_t threads[15];
int main() {
    WORD socketVersion=MAKEWORD(2,2);
    WSADATA wd;
    if(WSAStartup(socketVersion,&wd)!=0)    return 0;
//    cout<<"Welcome to chat room. Please login first."<<"\n";
    cin>>userid>>password;
    while(true){
        sclient=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
        bool iscnt=cnt();
        if(!iscnt){
            cout<<"Connection Failed"<<"\n";
            system("pause");
        }
        else    cout<<"Connection Succeeded"<<"\n"; //for test
        system("pause");    //for test
        if(!flg){
            int rc=pthread_create(&threads[1],NULL,msend,(void *)&(indexes[1]));
            if(rc!=0){
                cout<<"failed to send \n";
                exit(-1);
            }
        }
        int rc=pthread_create(&threads[2],NULL,mrec,(void *)&(indexes[2]));
        if(rc!=0){
            cout<<"falied to recieve \n";
            exit(-1);
        }
    }
    return 0;
}
