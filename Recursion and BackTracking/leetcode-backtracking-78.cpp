// 78. Subsets 
// 30 mins 
class Solution {
private:
    vector<vector<int>> result;
    void Recursivesubsets(vector<int>& nums, vector<int>& temp, int i) {
        // Base
        if(nums.size()==i){
            result.push_back(temp);
            return;
        }
        // Recur
        temp.push_back(nums[i]);
        Recursivesubsets(nums, temp, i+1);
        temp.pop_back();
        Recursivesubsets(nums, temp, i+1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        Recursivesubsets(nums, temp, 0);

        return result;
    }
};