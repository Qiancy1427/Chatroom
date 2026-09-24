//
// Created by qianchengyi on 2025/5/8.
//
#include <bits/stdc++.h>
#include <graphics.h>
#include <conio.h>
using namespace std;
char history[500][1000], msg[255];
int msglength;
extern int useridlen;
void initializerend(){
    initgraph(960, 540);
    setbkcolor(EGERGB(0x0, 0x0, 0x0));
    setcolor(EGERGB(0xff, 0xff, 0xff));
    line(0, 450, 960, 450);
    setfont(15, 0, "Consolas");
    setfillcolor(EGERGB(0x0, 0x0, 0x0));
    return ;
}

int readkb(){
    char ch = 0;
    while(true){
        ch = getch();
        if(ch == 13) break;
        if(ch == 27)    return -1;
        if(ch == 8){
            bar(50 + 8 * msglength, 480, 58 + 8 * msglength, 495);
            msg[msglength--] = 0;
            continue;
        }
        if(ch < 32 || ch > 127) continue;
        if(msglength >= 255)    break;
        msg[msglength++] = ch;
        outtextxy(50 + 8 * msglength - useridlen, 480, ch);
    }
    bar(0, 451, 960, 540);
    return msglength;
}

void rendhistory(int num){
    if(num < 30){
        outtextxy(0, num*15, history[num]);
    }
    else{
        bar(0, 0, 960, 450);
        for(int i = 0; i < 30; i++){
            outtextxy(0, i * 15, history[num-29+i]);
        }
    }
    return;
}
wstring paste(){
    wstring cbstring;
    if (OpenClipboard(nullptr)) {
        HANDLE hClipboardData = GetClipboardData(CF_UNICODETEXT);
        if (hClipboardData) {
            wchar_t* pwchData = static_cast<wchar_t*>(GlobalLock(hClipboardData));
            if (pwchData) {
                std::wstring clipboardText(pwchData);
                GlobalUnlock(hClipboardData);
                cbstring = clipboardText;
                std::wcout << L"Clipboard text: " << clipboardText << std::endl;
                // 输出剪贴板文本内容到控制台，已被注释掉
            }
        }
        CloseClipboard();
    }
    return cbstring;
}