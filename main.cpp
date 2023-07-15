#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
  unordered_map<char, int> values = {{'I', 1},   {'V', 5},   {'X', 10},
                                     {'L', 50},  {'C', 100}, {'D', 500},
                                     {'M', 1000}};
  int result = 0;

  for (int i = 0; i < s.length(); i++) {
    int value = values[s[i]];
    if (i < s.length() - 1 && value < values[s[i + 1]]) {
      result -= value;
    } else {
      result += value;
    }
  }

  return result;
}

int main() {
  string romanNumeral;

  do {
    cout << "Enter a Roman numeral (or 'q' to quit): ";
    cin >> romanNumeral;

    if (romanNumeral == "q") {
      break;
    }

    transform(romanNumeral.begin(), romanNumeral.end(), romanNumeral.begin(),
              ::toupper);
    int integerValue = romanToInt(romanNumeral);
    cout << "Integer value: " << integerValue << endl;

  } while (true);

  return 0;
}
