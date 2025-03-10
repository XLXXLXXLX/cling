#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <lldb/API/SBDebugger.h>
#include <lldb/API/SBProcess.h>
#include <memory>

namespace cling {
  namespace xlx {

    class DebuggerManager {
      std::shared_ptr<lldb::SBDebugger> debugger;
      std::shared_ptr<lldb::SBTarget> target;
      std::shared_ptr<lldb::SBProcess> process;

    public:
      DebuggerManager();
      auto getDebugger() { return debugger; }
      auto getTarget() { return target; }
      auto getProcess() { return process; }
    };
    DebuggerManager& getDebuggerManager();
  } // namespace xlx
} // namespace cling
#endif // DEBUGGER_H