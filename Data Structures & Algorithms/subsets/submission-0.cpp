class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> out;

        out.push_back({});

        for(int i{0}; out.size() < pow(2, nums.size()) * 5; ++i) {
            if(i >= out.size()) break;
            for (const auto& num: nums) {
                
                vector<int> temp{};
                copy(out[i].begin(), out[i].end(), back_inserter(temp));

                if(temp.end() != find(temp.begin(), temp.end(), num)) continue;

                temp.push_back(num);
                sort(temp.begin(), temp.end());
                if(out.end() != find(out.begin(), out.end(), temp)) continue;
                if (temp.size() > nums.size()) break;
                out.push_back(temp);

                if(out.size() > pow(2, nums.size())) break;
            }
            cout << "We outtie" << endl;
        }


        return out;
                
    }
};
