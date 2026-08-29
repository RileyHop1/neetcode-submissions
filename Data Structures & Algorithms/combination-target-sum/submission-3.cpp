class Solution {
public:

    vector<vector<int>> dfs(
        vector<int>::iterator front, 
        vector<int>::iterator back, 
        vector<int> seq, 
        int target
    ) {

        if (target == 0) return {seq};
        if (target < 0) return {};

        seq.push_back(*front);
        auto next = front + 1;


        auto left = dfs(front, back, seq, target - *front);
        seq.pop_back();
        if (next != back && target - *next >= 0) {
            auto right = dfs(next, back, seq, target);

            for(const auto& vec: right) {
                left.push_back(std::move(vec));
            }
        }

        return left;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
       auto left = dfs(nums.begin(), nums.end(), {nums.front()}, target - nums.front());
        if (nums.begin() + 1 != nums.end()) {
            auto right = dfs(nums.begin() + 1, nums.end(), {}, target);

            for(const auto& vec: right) {
                left.push_back(std::move(vec));
            }
        }

        return left;
    }

};
