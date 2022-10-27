#include "imports.h"
using namespace std::chrono;
class Timer {
  high_resolution_clock::time_point start;
  high_resolution_clock::duration duration;

 public:
  high_resolution_clock::time_point startClock() {
    this->start = high_resolution_clock::now();
    return this->start;
  }
  high_resolution_clock::rep stopClock() {
    high_resolution_clock::time_point stop = high_resolution_clock::now();
    this->duration = duration_cast<nanoseconds>(stop - this->start);
    return this->duration.count();
  }
};