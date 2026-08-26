#include <unordered_map>


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> s{};

        for (int i{0}; i < nums.size(); ++i) {
            int t = target - nums[i];
            if(s.contains(t)) return {s[t], i};
            s[nums[i]] = i;   
        }
        return {};
        
    }
};
