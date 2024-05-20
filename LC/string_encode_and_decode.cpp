#include <string>
#include <vector>

class Solution {
public:
  static std::string encode(std::vector<std::string> &strs) {
    std::string encoded_str = "";
    for (std::string s : strs) {
      encoded_str.append(s);
      encoded_str.append("*");
    }
    return encoded_str;
  }

  static std::vector<std::string> decode(std::string s) {
    std::vector<std::string> decoded_str{};
    std::string buffer{};

    for (auto i : s) {
      if (i == '*') {
        decoded_str.push_back(buffer);
        buffer = "";
      } else {
        buffer.push_back(i);
      }
    }

    return decoded_str;
  }
};

int main() {

  std::vector<std::string> encode_this{"this", "is", "a", "string"};
  std::string str = Solution::encode(encode_this);
  printf("encoded: %s\n", str.c_str());

  std::vector<std::string> vec = Solution::decode(str);
  for (std::string i : vec) {
    printf("%s\n", i.c_str());
  }

  return 0;
}
