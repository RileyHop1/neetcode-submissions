class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> tree;
        vector<vector<int>> out;

        int tree_pos = 0;

        tree.push_back({});

        for(const auto& num : nums) {
            int inital_size = tree.size();
            tree.resize(tree.size() * 2);


            for(tree_pos; tree_pos < inital_size; ++tree_pos) {
                vector<int> temp1{};
                vector<int> temp2{};
                copy(tree[tree_pos].begin(), tree[tree_pos].end(), back_inserter(temp1));
                copy(tree[tree_pos].begin(), tree[tree_pos].end(), back_inserter(temp2));
                temp1.push_back(num);

                tree.push_back(temp1);
                tree.push_back(temp2);
            }
        }
        int tree_size = tree.size();

        for(int i{tree_size - 1}; i >= tree_size - (int)pow(2, nums.size()); --i) {
            out.push_back(std::move(tree[i]));
        }

        return out;






    }
};
