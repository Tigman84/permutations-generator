#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void generate_permutations(vector<T>& nums, int start, vector<vector<T>>& result) {
    if (start == nums.size() - 1) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); ++i) {
        swap(nums[start], nums[i]);
        generate_permutations(nums, start + 1, result);
        swap(nums[start], nums[i]);
    }
}

template<typename T>
void print_permutations(const vector<vector<T>>& permutations) {
    for (const auto& perm : permutations) {
        for (const T& element : perm) {
            cout << element << " ";
        }
        cout << endl;
    }
}

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> all_permutations;
    generate_permutations(nums, 0, all_permutations);

    cout << "Permutations:" << endl;
    print_permutations(all_permutations);
    cout << "Total number of permutations: " << factorial(nums.size()) << endl;

    return 0;
}

