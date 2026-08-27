class Solution {
public:

    int trap(vector<int>& height) {

        
        int acc{0};
        int ts{0};
        int tp{0};

        int total = 0;
        for (int i{0}; i < (int)height.size() - 1; ) {
            int t1 = height[i];
            ts = -1;
            tp = i;
            for (int j{i + 1}; j < height.size(); ++j) {
                if (height[j] >= height[i]) {
                    ts = height[j];
                    tp = j;
                    break;
                }
                if(height[j] > ts) {
                    ts = height[j];
                    tp = j;
                }
            }
            
            int limit = min(t1, ts);
            for (int k = i + 1; k < tp; ++k) {
                total += max(0, limit - height[k]);  
            }
            if (tp <= i) i++;
            else i = tp;
        }
        
        return total;
        
    }
};