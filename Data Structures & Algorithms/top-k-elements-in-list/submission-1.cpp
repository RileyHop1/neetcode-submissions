#include <unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> fa;
        vector<vector<int>> va(nums.size()+1);
        vector<int> out;

        for(const auto& num: nums) {
            fa[num]++;
        } 
        for(const auto& a: fa) {
            va[a.second].push_back(a.first);
        }
        for(int i = va.size()-1; i > 0;) {
            if(out.size() == k) break;
            if(!va[i].empty()) { 
                out.push_back(va[i].back());
                va[i].pop_back();
            } else --i;
        }
        return out;


        
    }
};
