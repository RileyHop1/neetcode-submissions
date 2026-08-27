class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int front = 0;
        int back = matrix.size() - 1;
        int block = -1;

        while(front <= back) {
            int middle = (back + front)/2;
            if(
                matrix[middle][0] <= target &&
                target <= matrix[middle][matrix[middle].size()-1]
            ) {
                block = middle;
                break;
            } else if (target > matrix[middle][matrix[middle].size()-1]) front = middle + 1;
            else if (target < matrix[middle][0]) back = middle - 1;
            else {
                //Safty, so this isn't an unending loop
                front++;
                back--;
            }
        }
        if(block == -1) return false;

        front = 0;
        back = matrix[block].size()-1;

        while(front <= back) {
            int middle = (back + front)/2;
            if(target == matrix[block][middle]) return true;
            else if (target > matrix[block][middle]) front = middle + 1;
            else back = middle - 1;
        }
        return false;



        
    }
};
