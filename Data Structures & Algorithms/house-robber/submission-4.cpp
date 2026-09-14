#include <unordered_map>

class Solution {
public:
    int rob(vector<int>& nums) {
        
        unordered_map<int, int> m;

        if (nums.empty()) return 0;
    

        return max(dfs(m, 0, nums), dfs(m,1,nums));
    }

    int dfs(unordered_map<int, int>& m, int i, vector<int>& nums) {
        if (i >= nums.size()) return 0;
        if (m.contains(i)) return m[i];
        m[i] = max(dfs(m, i + 2, nums), dfs(m, i + 3, nums)) + nums[i];


        return m[i];
    }
};
