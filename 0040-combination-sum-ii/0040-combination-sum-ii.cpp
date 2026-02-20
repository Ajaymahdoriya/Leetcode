class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int start, vector<int>& arr, int target, vector<int>& curr) {
        if(target == 0){
            result.push_back(curr);
            return;
        }

        for(int i=start;i<arr.size();i++){
            if(arr[i] > target) break;
            if(i>start && arr[i]==arr[i-1]) continue;

            curr.push_back(arr[i]);
            backtrack(i+1, arr, target-arr[i], curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        backtrack(0, candidates, target, curr);
        return result;
    }
};