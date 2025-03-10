#include "global_logger.h"
#include <spdlog/common.h>
#include <spdlog/logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <type_traits>

namespace cling {
  namespace xlx {

    std::shared_ptr<spdlog::logger> logger;
    void initLogger() {
      logger = spdlog::stdout_color_mt("global_logger");

      logger->set_level(spdlog::level::trace);
      //   logger->set_level(spdlog::level::info);
      logger->set_pattern("%^[%Y-%m-%d %H:%M][%L][thread %t][%@][%!] %v%$");
    }
  } // namespace xlx
} // namespace cling
