#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>

class ArraySolutions {
public:
    static std::pair<int, int> two_sum(const std::vector<int>& values, const int target) {
        size_t i = 0; 
        size_t j = values.size() - 1;
        std::vector<std::pair<int, int>> indexed_values{j + 1};

        std::transform(
            values.begin(),
            values.end(),
            indexed_values.begin(),
            [&i](int value) { return std::make_pair(value, i++); }
        );

        std::sort(
            indexed_values.begin(), 
            indexed_values.end(), 
            [](auto& p1, auto& p2) { return p1.first < p2.first; }
        );

        i = 0;
        while (i < j) {
            const auto& v1 = indexed_values[i], v2 = indexed_values[j];
            int sum = v1.first + v2.first;

            if (sum == target) {
                return std::make_pair(v1.second, v2.second);
            } 
            else if (sum > target) {
                j--;
            }
            else {
                i++;
            }
        }

        return std::make_pair(-1, -1);
    }

    static std::pair<int, int> two_sum_hash(const std::vector<int>& values, const int target) {
        std::unordered_map<int, size_t> cached_values{};

        for(size_t i = 0; i < values.size(); i++) {
            int val = values[i];
            int remainder = target - val;
            const auto& it = cached_values.find(remainder);

            if (it != cached_values.end()) {
                return std::make_pair(i, it->second);
            } 
            else {
                cached_values[val] = i;
            }
        }

        return std::make_pair(-1, -1);
    }

    static unsigned int stocks_buy_and_sell(const std::vector<int>& prices) {
        int maxProfit = 0;
        int minValue = INT_MAX;

        for (const int price : prices) {
            if (minValue > price) {
                minValue = price;
            } else {    
                maxProfit = std::max(maxProfit, price - minValue);
            }
        }

        return maxProfit;
    }

    static bool contains_duplicate(const std::vector<int>& values) {
        std::set<int> cache{};

        for (const int value : values) {
            if (cache.contains(value)) {
                return true;
            }
            else {
                cache.insert(value);
            }
        }

        return false;
    }

    static std::vector<int> product_of_array_except_self(const std::vector<int>& values) {
        const size_t size = values.size();
        std::vector<int> pre(size), post(size), out(size);

        pre[0] = values[0];
        for(size_t i = 1; i < size; i++) {
            pre[i] = pre[i - 1] * values[i];
        }

        post[size - 1] = values[size - 1];
        for(int i = size - 2; i >= 0; i--) {
            post[i] = post[i + 1] * values[i];
        }

        int preval, postval;

        for(size_t i = 0; i < values.size(); i++) {
            preval = i == 0 ? 1 : pre[i - 1];
            postval = i == (size - 1) ? 1 : post[i + 1];
            
            out[i] = preval * postval;
        }

        return out;
    }

    static int subarray_sum(const std::vector<int>& values) {
        int maxSum = INT_MIN;
        int sum = 0;

        for (size_t i = 0; i < values.size(); i++) {
            sum += values[i];

            if (sum >= maxSum) {
                maxSum = sum;
            }

            if (sum < 0) {
                sum = 0;
            }
        }

        return maxSum;
    }
    
    static int subarray_product(const std::vector<int>& values) {
        int maxProduct = values[0];
        int minProduct = values[0];
        int answer = values[0];

        for(size_t i = 1; i < values.size(); i++) {
            int value = values[i];

            if (value < 0) {
                int temp = maxProduct;
                maxProduct = minProduct;
                minProduct = temp;
            }
            
            maxProduct = std::max(value, maxProduct * value);
            minProduct = std::min(value, minProduct * value);

            answer = std::max(answer, maxProduct);
        }

        return answer;
    }

    static int min_in_rotated(const std::vector<int>& values) {
        int minValue = INT_MAX;

        

        return minValue;
    }
};

class ArraySolvers {
public:
    static void two_sum_solver() {
        std::vector<int> values = {6, 4, 3, 2, 1, 24, 12, 3, 9, 4, 16, 7, 3};
        int target = 17;
        auto ans = ArraySolutions::two_sum(values, target);

        std::cout << "\nTwo Sum Solution:\n";
        std::cout << "Array: ";
        for (int v : values) {
            std::cout << v << " ";
        }
        std::cout << "\nTarget: " << target << std::endl;
        std::cout << "Answer: (" << ans.first << ", " << ans.second << ")" << std::endl;
    }

    static void two_sum_hash_solver() {
        std::vector<int> values = {6, 4, 3, 2, 1, 24, 12, 3, 9, 4, 16, 7, 3};
        int target = 17;
        auto ans = ArraySolutions::two_sum_hash(values, target);

        std::cout << "\nTwo Sum Solution (With Hash Map):\n";
        std::cout << "Array: ";
        for (int v : values) {
            std::cout << v << " ";
        }
        std::cout << "\nTarget: " << target << std::endl;
        std::cout << "Answer: (" << ans.first << ", " << ans.second << ")" << std::endl;
    }

    static void stocks_solver() {
        std::vector<int> values = {6, 4, 3, 2, 1, 24, 12, 3, 9, 4, 16, 7, 3};
        auto ans = ArraySolutions::stocks_buy_and_sell(values);

        std::cout << "\nStocks Buy And Sell:\n";
        std::cout << "Stocks: ";
        for (int v : values) {
            std::cout << v << " ";
        }
        std::cout << "\nAnswer: " << ans << std::endl;
    }

    static void contains_duplicate_solver() {
        std::vector<int> values = {6, 4, 3, 2, 1, 24, 12, 9, 16, 7};
        std::cout << "\nContains Duplicate:\n";
        std::cout << "Values: ";
        for (int v : values) {
            std::cout << v << " ";
        }
        std::cout << "\nAnswer: ";
        if (ArraySolutions::contains_duplicate(values)) {
            std::cout << "True" << std::endl;
        } else {
            std::cout << "False" << std::endl;
        }
    }

    static void product_of_array_solver() {
        std::vector<int> values = {-1,1,0,-3,3};
        auto ans = ArraySolutions::product_of_array_except_self(values);
    
        std::cout << "\nProduct of Array Except Self:\n";
        std::cout << "Values: ";
        for (int v : values) {
            std::cout << v << " ";
        }
        std::cout << "\nAnswer: ";
        for (int a : ans) {
            std::cout << a << " ";
        }
        std::cout << std::endl;
    }

    static void subarray_sum_solver() {
        // std::vector<int> values = {1, -4, 10, -1, 10, -4, 1};
        // std::vector<int> values = {-2, -1};
        // std::vector<int> values = {-2, 1};
        // std::vector<int> values = {-6, -10, -3, -3, -40, -2, -4, -40};
        // std::vector<int> values = {-1, -1, 2};
        // std::vector<int> values = {-1,-2,3,-1,-2,1,1};
        std::vector<int> values = {99, -100, 100, -20, 100, -1000, 99};
        auto ans = ArraySolutions::subarray_sum(values);
    
        std::cout << "\nMaximum Sum of Sub Array:\n";
        std::cout << "Values: ";
        for (int v : values) {
            std::cout << v << " ";
        }
        std::cout << "\nAnswer: " << ans << std::endl;
    }

    static void subarray_product_solver() {
        std::vector<int> values = {1,2,-3,0,-4,-5,-1};
        // std::vector<int> values = {0, 2};
        // std::vector<int> values = {3, -1, 4};
        // std::vector<int> values = {2,3,-2,4};
        // std::vector<int> values = {-2,0,-1};
        // std::vector<int> values = {-2,-3,7};
        // std::vector<int> values = {-3,-1,-1};
        auto ans = ArraySolutions::subarray_product(values);
    
        std::cout << "\nMaximum Product of Sub Array:\n";
        std::cout << "Values: ";
        for (int v : values) {
            std::cout << v << " ";
        }
        std::cout << "\nAnswer: " << ans << std::endl;
    }
};

int main() {
    ArraySolvers::two_sum_solver();
    ArraySolvers::two_sum_hash_solver();
    ArraySolvers::stocks_solver();
    ArraySolvers::contains_duplicate_solver();
    ArraySolvers::product_of_array_solver();
    ArraySolvers::subarray_sum_solver();
    ArraySolvers::subarray_product_solver();
    return 0;
}