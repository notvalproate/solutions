#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>

class StringSolutions {
public:
    static int longest_repeating_replacement(const std::string& str, const int k) {
        std::vector<int> frequencies(26);
        constexpr char UPPERCASE_A = 'A';

        auto incrementCharacterFrequency = [&frequencies](char letter) {
            int index = letter - UPPERCASE_A;
            frequencies[index]++;
        };

        auto decrementCharacterFrequency = [&frequencies](char letter) {
            int index = letter - UPPERCASE_A;
            frequencies[index]--;
        };

        int maxWindowLength = INT_MIN;
        int mostFrequent = INT_MIN;
        int windowStart = 0, windowEnd = 0;

        while (windowEnd < str.size()) {
            char endChar = str[windowEnd];
            incrementCharacterFrequency(endChar);

            mostFrequent = std::max(mostFrequent, frequencies[endChar - UPPERCASE_A]);
            int windowLength = windowEnd - windowStart + 1;

            if (mostFrequent + k < windowLength) {
                decrementCharacterFrequency(str[windowStart]);
                windowStart++;
            } else {
                maxWindowLength = std::max(maxWindowLength, windowLength);
            }

            windowEnd++;
        }

        return maxWindowLength;
    }
};  

class StringSolvers {
public:
    static void longest_repeating_replacement_solver() {
        // std::string str = "BAABAABBBAAA";
        // int k = 2;
        // std::string str = "BAAAB";
        // int k = 2;
        // std::string str = "AABABBA";
        // int k = 1;
        std::string str = "ABAB";
        int k = 0;
        auto ans = StringSolutions::longest_repeating_replacement(str, k);

        std::cout << "\nLongest Repeating Character Replacement Solution:" << std::endl;
        std::cout << "String: " + str << std::endl;
        std::cout << "Answer: " << ans << std::endl;
    }
};

int main() {
    StringSolvers::longest_repeating_replacement_solver();
    return 0;
}