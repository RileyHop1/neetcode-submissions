#include <unordered_map>


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> s{};

        for (int i{0}; i < nums.size(); ++i) {
            if(s.contains(nums[i])) return vector<int> {s[nums[i]], i};

            s[target - nums[i]] = i;
            
        }
        return vector<int> {};
        
    }
};
