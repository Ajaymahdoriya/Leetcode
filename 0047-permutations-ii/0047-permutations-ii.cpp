class Solution {
public:
set<vector<int>>ans;
void solve(int start,vector<int>& nums)
{
    if(start==nums.size())
    {
        ans.insert(nums);
        return;
    }
    for(int i=start;i<nums.size();i++)
    {
        swap(nums[i],nums[start]);
        solve(start+1,nums);
        swap(nums[i],nums[start]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(0,nums);
        vector<vector<int>>res;
        for(auto it=ans.begin();it!=ans.end();it++)
        {
            res.push_back(*it);
        }
        return res;
    }
};