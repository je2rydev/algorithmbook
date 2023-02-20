class Solution {
private:
    vector<vector<int>> result;
    void Recursivesubsets(vector<int>& nums, vector<int>& temp, int i) {
        // Base
        if(nums.size()==i){
            vector<int> tmp(temp.size(), 0);
            copy(temp.begin(), temp.end(), tmp.begin());
            sort(tmp.begin(), tmp.end());
            if(find(result.begin(), result.end(), tmp) == result.end())
                result.push_back(tmp);
            return;
        }
        // Recur

        temp.push_back(nums[i]);
        Recursivesubsets(nums, temp, i+1);
        temp.pop_back();
        Recursivesubsets(nums, temp, i+1);
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        Recursivesubsets(nums, temp, 0);

        return result;
    }
};