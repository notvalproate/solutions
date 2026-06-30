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
};

int main() {
    DPSolvers::climbing_stairs_solver();
    return 0;
}