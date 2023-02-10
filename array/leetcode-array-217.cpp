/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() <= 1)
            return false;
        sort(nums.begin(), nums.end());
        int prev = -10000000000;

        for (int i=0;i<nums.size(); i++){
            if(prev == nums[i])
                return true;
            prev = nums[i];
            
        }
        return false;
    }
};

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() <= 1)
            return false;
        
        // O(logN)
        sort(nums.begin(), nums.end());
        int prev = nums[0];

        // O(N)
        for (int i=1;i<nums.size(); i++){
            if(prev == nums[i])
                return true;
            prev = nums[i];
            
        }
        return false;
    }
};

/*
    1. do sort of nums
    2. compare previous index and current index
    3. If they are same, return false. 
*/
