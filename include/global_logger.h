#ifndef GLOBAL_LOGGER_H
#define GLOBAL_LOGGER_H

#include <memory>
#include <spdlog/spdlog.h>

namespace cling {
  namespace xlx {
    // 声明全局 logger 对象
    extern std::shared_ptr<spdlog::logger> logger;
    // 初始化 logger 的函数
    void initLogger();
  } // namespace xlx
} // namespace cling
#endif // GLOBAL_LOGGER_H