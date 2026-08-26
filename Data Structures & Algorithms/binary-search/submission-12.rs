impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {

        let mut end: usize = nums.len()-1;
        let mut start: usize = 0;

        if nums.len() == 1  {
            if nums[0] == target {
                return 0;
            } else {
                return -1;
            }
        }

        if nums.len() == 2 {
            if nums[0] == target {
                return 0;
            } else if nums[1] == target {
                return 1;
            } else { 
                return -1;
            }
        }

        while end >= start {
            let middle: usize = (start + end)/2;
            if nums[middle] == target {
                return middle as i32;
            } else if target > nums[middle] {
                start = middle+1;
            } else {
                end = middle-1;
            }
            
        }

        return -1

    }
}
