#ifndef GLOBAL_LOGGER_H
#define GLOBAL_LOGGER_H

#include <spdlog/spdlog.h>
#include <memory>

// 声明全局 logger 对象
extern std::shared_ptr<spdlog::logger> logger;

// 初始化 logger 的函数
void init_logger();

#endif // GLOBAL_LOGGER_H