#include <algorithm>
#include <vector>

class Interval {
public:
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class Solution {
public:
  bool canAttendMeetings(std::vector<Interval> &intervals) {
    std::sort(intervals.begin(), intervals.end(), compareFn);
    int size = intervals.size();

    for (int i{0}; i < size - 1; i++) {
      if (intervals[i].end > intervals[i + 1].start) {
        return false;
      }
    }

    return true;
  }

private:
  static bool compareFn(Interval i1, Interval i2) {
    return i1.start < i2.start;
  }
};
