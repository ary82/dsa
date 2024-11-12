#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class TimeMap {
public:
  TimeMap() {}

  void set(std::string key, std::string value, int timestamp) {
    kv[key].push_back({timestamp, value});
  }

  std::string get(std::string key, int timestamp) {
    int size = kv[key].size();

    int l{0};
    int r{size - 1};
    std::string res{};

    while (l <= r) {
      int mid{(l & r) + ((l ^ r) >> 1)};
      int ts{kv[key][mid].first};
      if (ts < timestamp) {
        res = kv[key][mid].second;
        l = mid + 1;
      } else if (ts == timestamp) {
        return kv[key][mid].second;
      } else {
        r = mid - 1;
      }
    }
    return res;
  }

private:
  std::unordered_map<std::string, std::vector<std::pair<int, std::string>>>
      kv{};
};
