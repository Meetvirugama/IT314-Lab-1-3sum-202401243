#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {


            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {-1, 0, 1, 2, -1, -4},
        {0, 0, 0, 0},
        {1, 2, -2, -1},
        {-2, 0, 1, 1, 2},
        {-4, -1, -1, 0, 1, 2, 2},
        {3, -2, -1, 0, 1, 2, -3},
        {5, -5, 0},
        {1, 1, -2},
        {0, 1, 1},
        {}
    };

    for (int t = 0; t < testCases.size(); t++) {

        cout << "Test Case " << t + 1 << ":\n";

        vector<int> nums = testCases[t];

        vector<vector<int>> ans = sol.threeSum(nums);

        if (ans.empty()) {
            cout << "No triplets found";
        }
        else {
            for (auto &triplet : ans) {
                cout << "[";

                for (int i = 0; i < triplet.size(); i++) {
                    cout << triplet[i];

                    if (i != triplet.size() - 1)
                        cout << ", ";
                }

                cout << "] ";
            }
        }

        cout << "\n\n";
    }

    return 0;
}