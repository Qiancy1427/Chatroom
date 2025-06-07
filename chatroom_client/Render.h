//
// Created by qianchengyi on 2025/5/8.
//
#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
wchar_t history[500][1000];
void initializerend(){
    initgraph(960, 540);
    setbkcolor(EGERGB(0x0, 0x0, 0x0));
    setcolor(EGERGB(0xff, 0xff, 0xff));
    line(0, 450, 960, 450);
    setfont(15, 0, "Consolas");
    setfillcolor(EGERGB(0x0, 0x0, 0x0));
    //getch();
    return;
}
wchar_t readkey(){
    key_msg k[3];
    for(int i=0; i<3; i++){
        k[i]=getkey();
        //cout<<k[i].key<<"\n";
        cout<<k[i].key<<"\n";
        if(k[i].key == 16 || k[i].key == 17 || k[i].key == 20)  i--;
    }
    return wchar_t (k[1].key);
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