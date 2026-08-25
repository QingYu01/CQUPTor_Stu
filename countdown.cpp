// countdown.cpp —— 控制台倒计时程序
// 功能：
//   1. 支持三种时长输入格式：秒数(90)、分:秒(1:30)、时:分:秒(0:1:30)
//   2. 用 std::chrono 精确计时（自动补偿 sleep 误差）
//   3. 终端实时刷新剩余时间
//   4. 倒计时结束时发出提示音
// 编译：g++ -std=c++20 countdown.cpp -o countdown.exe
#include <chrono>     // 时间库：steady_clock、seconds
#include <cstdio>     // sscanf：解析输入
#include <iomanip>    // setw、setfill：格式化输出
#include <iostream>   // cout、cin
#include <string>     // string
#include <thread>     // this_thread::sleep_until

#ifdef _WIN32
#include <windows.h>  // SetConsoleOutputCP：解决 Windows 控制台中文乱码
#endif

using namespace std;
using namespace chrono;

// 将输入的时间字符串解析为总秒数。
// 支持三种格式：
//   "90"      -> 90 秒
//   "1:30"    -> 1 分 30 秒
//   "0:1:30"  -> 0 时 1 分 30 秒
// 解析成功返回 true，并把结果写入 totalSeconds；否则返回 false。
bool parseTime(const string& input, int& totalSeconds) {
    int h = 0, m = 0, s = 0;

    if (sscanf(input.c_str(), "%d:%d:%d", &h, &m, &s) == 3) {
        totalSeconds = h * 3600 + m * 60 + s;   // 时:分:秒
    } else if (sscanf(input.c_str(), "%d:%d", &m, &s) == 2) {
        totalSeconds = m * 60 + s;              // 分:秒
    } else if (sscanf(input.c_str(), "%d", &s) == 1) {
        totalSeconds = s;                       // 纯秒数
    } else {
        return false;                           // 无法识别
    }
    return totalSeconds >= 0;                   // 不允许负数
}

// 在终端同一行刷新显示剩余时间，格式 HH:MM:SS。
// '\r' 让光标回到行首，从而实现原地覆盖刷新。
void showTime(int remaining) {
    int h = remaining / 3600;
    int m = (remaining % 3600) / 60;
    int s = remaining % 60;

    cout << '\r' << setfill('0') << setw(2) << h << ':'
         << setw(2) << m << ':' << setw(2) << s << flush;
}

// 倒计时主流程。
// 用 sleep_until 睡到"下一个整秒对应的时间点"，
// 而不是每轮固定 sleep 1 秒，这样能补偿上一轮的延时误差，
// 保证整个倒计时总时长精确等于 totalSeconds 秒。
void runCountdown(int totalSeconds) {
    auto start = steady_clock::now();  // 记录开始时刻

    for (int remaining = totalSeconds; remaining >= 0; --remaining) {
        // 第 remaining 秒应该显示的时刻 = start + (totalSeconds - remaining) 秒
        this_thread::sleep_until(start + seconds(totalSeconds - remaining));
        showTime(remaining);
    }

    cout << endl;
    cout << '\a' << "时间到！" << endl;  // '\a' 发出系统提示音
}

int main() {
#ifdef _WIN32
    // 让 Windows 控制台按 UTF-8 显示中文，避免乱码
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    cout << "=== 倒计时程序 ===" << endl;
    cout << "请输入倒计时时长，支持三种格式：" << endl;
    cout << "  1. 秒数      例如: 90" << endl;
    cout << "  2. 分:秒     例如: 1:30" << endl;
    cout << "  3. 时:分:秒  例如: 0:1:30" << endl;
    cout << ">>> ";

    string input;
    getline(cin, input);  // 读取整行输入

    int totalSeconds;
    if (!parseTime(input, totalSeconds)) {
        cerr << "输入格式不正确，程序退出。" << endl;
        return 1;
    }
    if (totalSeconds == 0) {
        cout << "倒计时时长为 0，直接结束。" << endl;
        return 0;
    }

    cout << "开始倒计时 " << totalSeconds << " 秒，按 Ctrl+C 可提前结束..." << endl;
    runCountdown(totalSeconds);

    return 0;
}
