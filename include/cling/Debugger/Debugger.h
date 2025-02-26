#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <lldb/API/SBDebugger.h>
#include <memory>

// 声明全局 debugger 对象
extern std::shared_ptr<lldb::SBDebugger> global_debugger;

// 初始化 debugger 的函数
void init_debugger();

#endif // DEBUGGER_H