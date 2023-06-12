#include "imports.h"
#include "timer.h"
template <typename Func, typename Obj, typename... Args>
auto measureMethodPerformance(int iterations, Func&& func, Obj&& obj,
                              Args&&... args) {
  // Wrap the method call in a lambda function
  auto methodCall = [&](auto&&... capturedArgs) {
    return (std::forward<Obj>(obj).*std::forward<Func>(func))(
        std::forward<decltype(capturedArgs)>(capturedArgs)...);
  };

  // Call measureFunctionPerformance with the lambda function
  return measureFunctionPerformance(iterations, methodCall,
                                    std::forward<Args>(args)...);
}

template <typename Func, typename... Args>
auto measureFunctionPerformance(int iterations, Func&& func, Args&&... args) {
  Timer timer;
  double totalTime = 0.0;
  using ReturnType = decltype(func(std::forward<Args>(args)...));

  ReturnType result;

  // Warm-up phase
  for (int i = 0; i < iterations; i++) {
    timer.startClock();
    result = func(std::forward<Args>(args)...);
    timer.stopClock();
  }

  // Actual measurement phase
  for (int i = 0; i < iterations; i++) {
    timer.startClock();
    result = func(std::forward<Args>(args)...);
    double elapsed = static_cast<double>(timer.stopClock());
    totalTime += elapsed;
  }

  double averageTime = totalTime / iterations;
  return std::make_pair(averageTime, result);
}