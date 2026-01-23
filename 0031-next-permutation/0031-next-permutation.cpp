class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //firstly we have to find that index from the right where the sequence stops increasing.
        int idx = -1;
        int n = nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }

        //if breaking point does not found then reverse the array
        if(idx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }


        //find the smallest element greater than nums[idx] on the right side, then swap
        for(int i=n-1; i>idx; i--){
            if(nums[i] > nums[idx]){
                swap(nums[idx], nums[i]);
                break;
            }
        }


        //reverse the subarray from idx+1 to end to get the smallest order
        reverse(nums.begin() + idx + 1, nums.end());
        return ;
    }
};