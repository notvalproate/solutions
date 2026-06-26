#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
#include <bitset>
#include <cstdint>

class BinarySolutions {
public:
    static int set_bit_count(int a) {
        int count = 0;
        while (a != 0) {
            count += a & 0b1;
            a = a >> 1;
        }
        return count;
    }

    static std::vector<int> counting_bits(int n) {
        std::vector<int> counts(n + 1);
        int powerOfTwo = 1;

        for(int i = 1; i <= n; i++) {
            if (powerOfTwo * 2 == i) {
                powerOfTwo = i;
            }

            counts[i] = counts[i - powerOfTwo] + 1;
        }

        return counts;
    }

    static int sum_of_two(int a, int b) {
        while (b != 0) {
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

    static int reverse_bits(uint32_t a) {
        // int result = 0;
        // for (int i = 0; i < 32; i++) {
        //     result = (result << 1) | (a & 1);
        //     a = a >> 1;
        // }
        // return result;

        a = (a & 0x0000FFFF) << 16 | (a & 0xFFFF0000) >> 16;
        a = (a & 0x00FF00FF) << 8 | (a & 0xFF00FF00) >> 8;
        a = (a & 0x0F0F0F0F) << 4 | (a & 0xF0F0F0F0) >> 4;
        a = (a & 0x33333333) << 2 | (a & 0xCCCCCCCC) >> 2;
        a = (a & 0x55555555) << 1 | (a & 0xAAAAAAAA) >> 1;

        return a;
    }
};  

class BinarySolvers {
public:
    static void set_bit_count_solver() {
        int a = 11;
        auto ans = BinarySolutions::set_bit_count(a);

        std::cout << "\nSet Bit Count:\n";
        std::cout << "A: " << a << std::endl;
        std::cout << "Answer: " << ans << std::endl;
    }

    static void counting_bits_solver() {
        int n = 5;
        auto ans = BinarySolutions::counting_bits(5);
    
        std::cout << "\nCounting Bits Till N:\n";
        std::cout << "N: " << n << std::endl;
        std::cout << "Answer: ";
        for (int v : ans) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

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

    static void reverse_bits_solver() {
        int n = 43261596;
        int ans = BinarySolutions::reverse_bits(n);

        std::cout << "\nReverse Bits Solution:\n";
        std::cout << "N: " << n << std::endl;
        std::cout << "Answer: " << ans << std::endl;
    }
};

int main() {
    BinarySolvers::set_bit_count_solver();
    BinarySolvers::counting_bits_solver();
    BinarySolvers::sum_of_two_solver();
    BinarySolvers::missing_number_solver();
    BinarySolvers::reverse_bits_solver();
    return 0;
}