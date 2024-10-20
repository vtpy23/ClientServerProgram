#include <windows.h>
#include <iostream>
#include <sstream>
#include <tchar.h>

std::wstringstream activeAppTitlesStream;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    if (IsWindowVisible(hwnd)) {
        TCHAR windowTitle[256];
     
        GetWindowText(hwnd, windowTitle, sizeof(windowTitle) / sizeof(TCHAR));

        
        if (_tcslen(windowTitle) > 0) {
            activeAppTitlesStream << windowTitle << L"\n"; 
        }
    }
    return TRUE; 
}


std::wstring ListVisibleWindows() {
    EnumWindows(EnumWindowsProc, 0);
    return activeAppTitlesStream.str(); 
}


