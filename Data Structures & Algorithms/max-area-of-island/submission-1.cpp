class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int largest{0};


        for (int i{0}; i < grid.size(); ++i) {
            for(int j{0}; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    int temp = markAdjacent(grid, i, j);
                    if (temp > largest) largest = temp;
                } 
            }
        }
        return largest;


        
    }
    int markAdjacent(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 0;

        int right = 0;
        int left = 0;
        int up = 0;
        int down = 0; 

        if(i + 1 < grid.size() && grid[i + 1][j] == 1) {
            down = markAdjacent(grid, i + 1, j);
        }
        if(j + 1 < grid[i].size() && grid[i][j + 1] == 1) {
            right = markAdjacent(grid, i, j + 1);
        }
        if(i - 1 >= 0 && grid[i - 1][j] == 1) {
            up = markAdjacent(grid, i - 1, j);
        }
        if(j - 1 >= 0 && grid[i][j - 1] == 1) {
            left = markAdjacent(grid, i, j - 1);
        }

        return right + left + up + down + 1;

    }
};
