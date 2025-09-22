#include <iostream>
#include <csignal>
#include <chrono>
#include <thread>
//增加了一处修改
// 1. 定义一个信号处理函数
//一个新修改111111111111111
//一个新修改222222222222222

void signal_handler(int signum) {
    std::cout << "\n捕获到中断信号 (" << signum << ")！正在准备退出..." << std::endl;
    // 在这里可以添加保存文件的代码
    std::cout << "工作已保存。再见！" << std::endl;
    exit(signum); // 正常退出程序
}

int main() {
    // 2. 注册信号处理函数
    // 告诉操作系统：如果收到了 SIGINT 信号(Ctrl+C)，请去调用 signal_handler 函数
    signal(SIGINT, signal_handler);

    std::cout << "程序正在运行，请按 Ctrl+C 来中断它..." << std::endl;
    int i = 0;
    while(true) {
        std::cout << "正在处理任务 " << ++i << "..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1)); // 暂停1秒
    }

    return 0; // 这行永远不会被执行到
}
