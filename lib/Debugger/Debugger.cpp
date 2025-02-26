#include <lldb/API/SBDebugger.h>

#include "cling/Debugger/Debugger.h"
#include <memory>
#include <type_traits>

std::shared_ptr<lldb::SBDebugger> global_debugger;

void init_debugger() {
  lldb::SBDebugger::Initialize();
  global_debugger =
      std::make_shared<lldb::SBDebugger>(lldb::SBDebugger::Create(true));
  global_debugger->SetAsync(false); // 设为同步模式
}