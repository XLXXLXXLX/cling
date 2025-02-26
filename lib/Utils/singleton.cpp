
#include <memory>
#include <spdlog/logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <type_traits>

template <typename T> class Singleton {
private:
  Singleton() {}

  // 禁止拷贝构造和赋值操作
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

public:
  static T& getInstance() {
    static T instance; // 静态局部变量，确保单例
    return instance;   // 返回单例对象的引用
  }
  template <
      std::enable_if_t<std::is_same_v<T, std::shared_ptr<spdlog::logger>>, T>>
  void initLogger() {
    auto logger = getInstance();
    logger = spdlog::stdout_color_mt("logger");
    logger->set_level(spdlog::level::trace);
    logger->set_pattern("%^[%Y-%m-%d %H:%M][%L][thread %t][%@][%!] %v%$");
  }
};
