#include <iostream>
#include <vector>

class DPSolutions {
public:
    static int climbing_stairs(const int n) {
        std::vector<int> cache(n + 1, -1);
        cache[0] = 1;
        cache[1] = 1;
    
        for (int i = 2; i <= n; i++) {
            cache[i] = cache[i - 1] + cache[i - 2];
        }

        return cache[n];
    }

    static void n_bit_more_ones(int n) {
        if (n == 0) {
            return;
        }

        auto n_bits = [&](this auto self, int countOfOnes, int countOfZeroes, std::string number) -> void {
            if (countOfZeroes + countOfOnes == n) {
                std::cout << number << std::endl;
                return;
            }

            self(countOfOnes + 1, countOfZeroes, number + "1");

            if (countOfZeroes != countOfOnes - 1) 
                self(countOfOnes, countOfZeroes + 1, number + "0");
        };

        n_bits(1, 0, "1");
    }
};  

class DPSolvers {
public:
    static void climbing_stairs_solver() {
        int n = 5;
        auto ans = DPSolutions::climbing_stairs(n);

        std::cout << "\nClimbing Stairs Solution:" << std::endl;
        std::cout << "N: " << n << std::endl;
        std::cout << "Answer: " << ans << std::endl;
    }

    static void n_bit_more_ones_solver() {
        int n = 5;

        std::cout << "\nN-Bit Numbers With More 1s All Prefixes Solution:" << std::endl;
        std::cout << "N: " << n << "\nAnswers:" << std::endl;
        DPSolutions::n_bit_more_ones(n);
    }
};

/*
N bit number
01001010-> TILL N BITS

EVERY PREFIX OF THE NUMBER HAS count of 1s > 0s

00000

countOfOnes + countOfZeros = n 
    return 1;
count of 0s >= count of 1s
- set to 1
    -> countOfOnes++
    - next bit
- next bit
    -> countOfZeros++
    set it to 1

*/

int main() {
    DPSolvers::climbing_stairs_solver();
    DPSolvers::n_bit_more_ones_solver();
    return 0;
}