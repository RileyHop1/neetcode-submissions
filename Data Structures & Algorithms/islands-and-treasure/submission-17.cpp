#include <list>

class Solution {
public:
    
    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        list<pair<int, int>> q;
        for (int i{0}; i < grid.size(); ++i) {
            for(int j{0}; j < grid[i].size(); ++j) {
                if (grid[i][j] == 0)  q.push_back({i, j});
            }
        }

        while(!q.empty()) {
            auto [i, j] = q.front();
            int dist = grid[i][j] + 1;
            if (i - 1 >= 0 && dist < grid[i-1][j]) {
                q.push_back({i-1, j});
                grid[i-1][j] = dist;
            }
            if (i + 1 < grid.size() && dist < grid[i+1][j]) {
                q.push_back({i+1, j});
                grid[i+1][j] = dist;
            }
            if (j - 1 >= 0 && dist < grid[i][j-1]) {
                q.push_back({i, j-1});
                grid[i][j-1] = dist;
            }
            if (j + 1 < grid[i].size() && dist < grid[i][j+1]) {
                q.push_back({i, j+1});
                grid[i][j+1] = dist;
            }
            q.pop_front();

        }
        
    }
};
