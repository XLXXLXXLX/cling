#include <cassert>
#include <lldb/API/SBDebugger.h>

#include "cling/Debugger/Debugger.h"
#include <lldb/API/SBProcess.h>
#include <lldb/API/SBTarget.h>
#include <memory>
#include <type_traits>
namespace cling {
  namespace xlx {

    DebuggerManager::DebuggerManager() {

      lldb::SBDebugger::Initialize();

      debugger =
          std::make_shared<lldb::SBDebugger>(lldb::SBDebugger::Create(true));
      debugger->SetAsync(false); // 设为同步模式

      target = std::make_shared<lldb::SBTarget>(debugger->CreateTarget(""));
      assert(target->isValid());

      process = std::make_shared<lldb::SBProcess>(
          target->LaunchSimple(NULL, NULL, "."));
      assert(process.IsValid());
    }
    DebuggerManager& getDebuggerManager() {
      static DebuggerManager dm;
      return dm;
    }
  } // namespace xlx
} // namespace cling