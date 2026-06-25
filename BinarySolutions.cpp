#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>

class BinarySolutions {
public:
    static int sum_of_two(int a, int b) {
        while(b != 0) {
            int c = a & b;
            a = a ^ b;
            b = c << 1;
        }
        return a;
    }

    static int missing_number(const std::vector<int>& values) {
        size_t expected = values.size() + 1;
        int xor1 = 0, xor2 = 0;

        for(const int val : values) {
            xor1 ^= val;
        }

        for(int i = 1; i <= expected; i++) {
            xor2 ^= i;
        }

        return xor1 ^ xor2;
    }
};  

class BinarySolvers {
public:
    static void sum_of_two_solver() {
        int a = 5, b = 11;
        auto ans = BinarySolutions::sum_of_two(a, b);

        std::cout << "\nSum of Two:\n";
        std::cout << "A: " << a << ", B: " << b << std::endl;
        std::cout << "Answer: " << ans << std::endl;
    }

    static void missing_number_solver() {
        std::vector<int> values = {2, 3, 6, 7, 8, 1, 4};
        auto ans = BinarySolutions::missing_number(values);

        std::cout << "\nMissing Number Solution:\n";
        std::cout << "Array: ";
        for (int v : values) {
            std::cout << v << " ";
        }
        std::cout << "\nAnswer: " << ans << std::endl;
    }
};

int main() {
    BinarySolvers::missing_number_solver();
    BinarySolvers::sum_of_two_solver();
    return 0;
}