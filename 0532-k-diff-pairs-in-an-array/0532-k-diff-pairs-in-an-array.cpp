class Solution {
public:

    int bs(vector<int>& nums , int start,int x){
        int end = nums.size()-1;
       
        while(start <= end){
            int mid = start + ( end - start)/2;
            if(nums[mid] == x){
                return mid;
            }
            else if(nums[mid] > x){
                end = mid - 1 ;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<pair<int,int>> ans;
        for(int i =0;i<nums.size();i++){
            if(bs(nums, i+1, nums[i]+k) != -1){
                ans.insert({nums[i] ,nums[i] + k});
            }
        }
        return ans.size();


        // by two pointer 
        // int i =0;
        // int j= 1;
        // set<pair<int,int>> ans;
        // sort(nums.begin(),nums.end());
        // while(j < nums.size()){
        //     if(nums[j] - nums[i] == k){
        //          ans.insert({nums[i],nums[j]});
        //          i++;
        //          j++;
                 
        //     }
        //     else if(nums[j] - nums[i] > k){
        //         i++;
        //     }
        //     else {
        //         j++;
        //     }
        //     if(i==j) j++;
        // }
        // return ans.size();


    }
};