#include <unordered_map>

class Solution {
public:
    int rob(vector<int>& nums) {

        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums.back();
        
        unordered_map<int, int> m;

        int first = max(dfs(m, 0, nums, nums.size()-1)
            , dfs(m,1,nums, nums.size()-1));

        m.clear();

        int second = max(dfs(m, 1, nums, nums.size())
            , dfs(m,2,nums, nums.size()));

        return max(first, second);
    }

    int dfs(unordered_map<int, int>& m, int i, vector<int>& nums, int size) {
        if (i >= size) return 0;
        if (m.contains(i)) return m[i];
        m[i] = max(dfs(m, i + 2, nums, size)
            , dfs(m, i + 3, nums, size)) + nums[i];
        return m[i];
    }
};