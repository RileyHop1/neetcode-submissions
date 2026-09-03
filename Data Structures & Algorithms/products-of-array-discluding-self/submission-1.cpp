class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int navTot{1};
        bool hasZero{false};
        vector<int> output;

        for (const auto& num: nums) {
            if(num == 0 && !hasZero) {
                hasZero = true;
            } else {
                navTot *= num;
            }
        }
        for (const auto& num: nums) {
            if(num == 0 && hasZero) {
                output.push_back(navTot);
            } else if (hasZero) {
                output.push_back(0);
            } else {
                output.push_back(navTot/num);
            }
        }
        return output;


    }
};
