#include <windows.h>
#include <iostream>
#include <sstream>
#include <tchar.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace cv;
using namespace std;

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

bool imageCapture() {
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "!" << endl;
        return false;
    }
    Mat frame;
    cap >> frame;
    if (frame.empty()) {
        cout << "!" << endl;
        return false;
    }
    imwrite("D:\captured_image.jpg", frame);  
    cap.release();

    return true;
}

