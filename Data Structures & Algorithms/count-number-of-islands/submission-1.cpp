class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands{0};


        for (int i{0}; i < grid.size(); ++i) {
            for(int j{0}; j < grid[i].size(); ++j) {
                if (grid[i][j] == 'x') continue;
                if (grid[i][j] == '1') {
                    islands++;
                    markAdjacent(grid, i, j);
                } else grid[i][j] = 'x'; 
            }
        }
        return islands;


        
    }
    void markAdjacent(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = 'x'; 

        if(i + 1 < grid.size() && grid[i + 1][j] == '1') {
            markAdjacent(grid, i + 1, j);
        }
        if(j + 1 < grid[i].size() && grid[i][j + 1] == '1') {
            markAdjacent(grid, i, j + 1);
        }
        if(i - 1 >= 0 && grid[i - 1][j] == '1') {
            markAdjacent(grid, i - 1, j);
        }
        if(j - 1 >= 0 && grid[i][j - 1] == '1') {
            markAdjacent(grid, i, j - 1);
        }

    }
    
};
