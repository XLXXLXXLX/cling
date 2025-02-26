#ifdef LLDB_STUFF
#include <iostream>
#include "lldb/API/SBDebugger.h"

int main() {
    lldb::SBDebugger::Initialize();
    lldb::SBDebugger debugger = lldb::SBDebugger::Create();
    debugger.SetAsync(false);

    std::cout << "LLDB 调试器已初始化！" << std::endl;

    lldb::SBDebugger::Terminate();
    return 0;
}
#endif