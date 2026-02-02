class Solution {
public:

    void summation(vector<vector<int>>& ans,vector<int>& candi,vector<int>& digits, int tar,int k,int start){

        if(k==tar){
            ans.push_back(digits);
            return;
        }

        for(int i=start;i<candi.size();i++){

            if(k+candi[i]<=tar){
                digits.push_back(candi[i]);
                summation(ans,candi,digits,tar,k+candi[i],i);
                digits.pop_back();
            }
            else if(k+candi[i]>tar) break;       //pruning

        }
    }

    vector<vector<int>> combinationSum(vector<int>& candi, int tar) {
        
        vector<vector<int>> ans;
        vector<int> digits;
        sort(candi.begin(),candi.end());
        int k=0;
        int start=0;
        summation(ans,candi,digits,tar,k,start);
        return ans;
    }
};