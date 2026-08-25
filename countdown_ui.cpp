// countdown_ui.cpp —— 简易图形界面倒计时程序（Win32 API，无第三方依赖）
// 功能：
//   1. 输入框输入时长，支持 90 / 1:30 / 0:1:30 三种格式
//   2. "开始"按钮启动倒计时，"停止"按钮提前结束
//   3. 大号字体实时刷新剩余时间 HH:MM:SS
//   4. 最后 5 秒数字变红，倒计时结束发出提示音
// 编译：g++ -std=c++20 countdown_ui.cpp -o countdown_ui.exe -mwindows -lgdi32
#include <windows.h>
#include <cmath>    // ceil
#include <cwchar>   // swscanf
#include <string>

using namespace std;

// ---- 控件 ID ----
#define IDC_EDIT_TIME   1001   // 输入框
#define IDC_BTN_START   1002   // 开始按钮
#define IDC_BTN_STOP    1003   // 停止按钮
#define IDC_LBL_REMAIN  1004   // 剩余时间标签

// ---- 全局变量 ----
HINSTANCE g_hInst      = NULL;
HWND      g_hEdit      = NULL;  // 输入框
HWND      g_hBtnStart  = NULL;  // 开始按钮
HWND      g_hBtnStop   = NULL;  // 停止按钮
HWND      g_hLblRemain = NULL;  // 剩余时间标签
HFONT     g_hBigFont   = NULL;  // 大字字体
ULONGLONG g_endTick    = 0;     // 倒计时结束时刻（毫秒）
bool      g_running    = false; // 是否正在倒计时
bool      g_warning    = false; // 最后 5 秒警告状态（数字变红）

// 解析时间字符串（宽字符版本），逻辑与命令行版相同。
// 支持 "90"、"1:30"、"0:1:30" 三种格式；成功返回 true。
bool parseTimeW(const wstring& input, int& totalSeconds) {
    int h = 0, m = 0, s = 0;
    int consumed = 0;   // %n：记录解析已消费的字符数，用于检查多余内容

    if (swscanf(input.c_str(), L"%d:%d:%d%n", &h, &m, &s, &consumed) == 3) {
        totalSeconds = h * 3600 + m * 60 + s;   // 时:分:秒
    } else if (swscanf(input.c_str(), L"%d:%d%n", &m, &s, &consumed) == 2) {
        totalSeconds = m * 60 + s;              // 分:秒
    } else if (swscanf(input.c_str(), L"%d%n", &s, &consumed) == 1) {
        totalSeconds = s;                       // 纯秒数
    } else {
        return false;                           // 无法识别
    }

    // 跳过结尾空白后若还有内容（如 "1:2:3:4"），说明输入多余，判为非法
    const wchar_t* rest = input.c_str() + consumed;
    while (*rest == L' ' || *rest == L'\t') ++rest;
    if (*rest != L'\0') return false;

    return totalSeconds >= 0;                   // 不允许负数
}

// 把总秒数格式化为 HH:MM:SS 文本
wstring formatTime(int total) {
    int h = total / 3600;
    int m = (total % 3600) / 60;
    int s = total % 60;

    wchar_t buf[16];
    swprintf(buf, 16, L"%02d:%02d:%02d", h, m, s);
    return wstring(buf);
}

// 刷新剩余时间显示。
// 用 GetTickCount64 计算"结束时刻 - 当前时刻"得到精确剩余毫秒，
// 避免每秒递减带来的累积误差；到点则停止计时并提示。
void updateDisplay(HWND hWnd) {
    ULONGLONG now = GetTickCount64();

    if (now >= g_endTick) {   // 时间到
        KillTimer(hWnd, 1);
        g_running = false;
        g_warning = false;
        SetWindowTextW(g_hLblRemain, L"时间到！");
        EnableWindow(g_hBtnStart, TRUE);
        EnableWindow(g_hBtnStop, FALSE);
        InvalidateRect(g_hLblRemain, NULL, TRUE);  // 重绘以恢复蓝色
        MessageBeep(MB_ICONEXCLAMATION);           // 提示音
        return;
    }

    int remaining = (int)ceil((double)(g_endTick - now) / 1000.0);
    SetWindowTextW(g_hLblRemain, formatTime(remaining).c_str());

    bool warn = (remaining <= 5);                  // 最后 5 秒变红
    if (warn != g_warning) {
        g_warning = warn;
        InvalidateRect(g_hLblRemain, NULL, TRUE);  // 触发重绘更新颜色
    }
}

// 点击"开始"：读取输入、校验格式并启动倒计时
void startCountdown(HWND hWnd) {
    // 读取输入框内容
    wstring input;
    int len = GetWindowTextLengthW(g_hEdit);
    if (len > 0) {
        input.resize(len + 1);
        GetWindowTextW(g_hEdit, &input[0], len + 1);
        input.resize(len);
    }

    int total = 0;
    if (!parseTimeW(input, total) || total <= 0) {
        MessageBoxW(hWnd,
            L"输入格式不正确！\n支持三种格式：\n  秒数(90)、分:秒(1:30)、时:分:秒(0:1:30)",
            L"倒计时", MB_OK | MB_ICONWARNING);
        return;
    }

    g_endTick = GetTickCount64() + (ULONGLONG)total * 1000;
    g_running = true;
    g_warning = false;
    SetTimer(hWnd, 1, 200, NULL);        // 每 200ms 刷新一次显示
    EnableWindow(g_hBtnStart, FALSE);
    EnableWindow(g_hBtnStop, TRUE);
    updateDisplay(hWnd);                 // 立即显示一次
}

// 点击"停止"：结束倒计时并清零显示
void stopCountdown(HWND hWnd) {
    KillTimer(hWnd, 1);
    g_running = false;
    g_warning = false;
    SetWindowTextW(g_hLblRemain, L"00:00:00");
    EnableWindow(g_hBtnStart, TRUE);
    EnableWindow(g_hBtnStop, FALSE);
    InvalidateRect(g_hLblRemain, NULL, TRUE);
}

// 窗口过程：负责创建控件、处理按钮点击、定时刷新和绘制颜色
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {

    case WM_CREATE: {
        // 顶部说明文字
        CreateWindowW(L"STATIC", L"请输入倒计时时长（90 / 1:30 / 0:1:30）：",
                      WS_CHILD | WS_VISIBLE, 12, 14, 376, 20, hWnd, NULL, g_hInst, NULL);

        // 输入框
        g_hEdit = CreateWindowW(L"EDIT", L"",
                      WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
                      12, 40, 190, 26, hWnd, (HMENU)IDC_EDIT_TIME, g_hInst, NULL);

        // 开始 / 停止 按钮
        g_hBtnStart = CreateWindowW(L"BUTTON", L"开始",
                      WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
                      212, 40, 72, 26, hWnd, (HMENU)IDC_BTN_START, g_hInst, NULL);
        g_hBtnStop = CreateWindowW(L"BUTTON", L"停止",
                      WS_CHILD | WS_VISIBLE | WS_DISABLED,
                      294, 40, 72, 26, hWnd, (HMENU)IDC_BTN_STOP, g_hInst, NULL);

        // 大号剩余时间标签
        g_hLblRemain = CreateWindowW(L"STATIC", L"00:00:00",
                      WS_CHILD | WS_VISIBLE | SS_CENTER,
                      12, 90, 376, 100, hWnd, (HMENU)IDC_LBL_REMAIN, g_hInst, NULL);

        // 设置控件字体
        HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
        SendMessageW(g_hEdit,      WM_SETFONT, (WPARAM)hFont, TRUE);
        SendMessageW(g_hBtnStart,  WM_SETFONT, (WPARAM)hFont, TRUE);
        SendMessageW(g_hBtnStop,   WM_SETFONT, (WPARAM)hFont, TRUE);

        // 时间标签使用大号等宽粗体（Consolas），显示更醒目
        g_hBigFont = CreateFontW(-52, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                      DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                      CLEARTYPE_QUALITY, DEFAULT_PITCH, L"Consolas");
        SendMessageW(g_hLblRemain, WM_SETFONT, (WPARAM)g_hBigFont, TRUE);
        return 0;
    }

    case WM_COMMAND: {
        switch (LOWORD(wParam)) {
        case IDC_BTN_START: startCountdown(hWnd); return 0;
        case IDC_BTN_STOP:  stopCountdown(hWnd);  return 0;
        }
        break;
    }

    case WM_TIMER:
        if (wParam == 1) updateDisplay(hWnd);   // 定时刷新剩余时间
        return 0;

    case WM_CTLCOLORSTATIC: {
        // 给时间标签上色：普通状态蓝色，最后 5 秒红色；其余控件用默认
        if ((HWND)lParam == g_hLblRemain) {
            HDC hdc = (HDC)wParam;
            SetTextColor(hdc, g_warning ? RGB(220, 30, 30) : RGB(20, 90, 200));
            SetBkMode(hdc, TRANSPARENT);
            return (LRESULT)GetStockObject(WHITE_BRUSH);
        }
        break;
    }

    case WM_DESTROY:
        DeleteObject(g_hBigFont);   // 释放字体
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hWnd, msg, wParam, lParam);
}

// 程序入口
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow) {
    g_hInst = hInst;

    // 注册窗口类
    WNDCLASSW wc = {};
    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = hInst;
    wc.hCursor       = LoadCursorW(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);   // 白色背景
    wc.lpszClassName = L"CountdownWindow";
    RegisterClassW(&wc);

    // 创建固定大小的主窗口（去掉最大化和拉伸边框）
    HWND hWnd = CreateWindowW(L"CountdownWindow", L"倒计时",
                  WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
                  CW_USEDEFAULT, CW_USEDEFAULT, 404, 248,
                  NULL, NULL, hInst, NULL);
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // 消息循环
    MSG msg = {};
    while (GetMessageW(&msg, NULL, 0, 0)) {
        // IsDialogMessage 让编辑框里按回车直接触发"开始"按钮
        if (!IsDialogMessageW(hWnd, &msg)) {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }
    return (int)msg.wParam;
}
