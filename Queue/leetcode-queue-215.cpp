/*
215. Kth Largest Element in an Array
Time limited
*/

class Solution {
private:
    vector<int> arr;

public:
    void insertElement(int newElement){
        int i=0;
        int j=0;
        int t=0;
        for(t=0; t<arr.size(); t++){
            if(arr[t] < newElement)
                break;
        }
        arr.insert(arr.begin()+t, newElement);
    }

    int findKthLargest(vector<int>& nums, int k) {
        for(int i=0; i<nums.size() ; i++){
            insertElement(nums[i]);
        }

        return arr[k-1];
    }
};