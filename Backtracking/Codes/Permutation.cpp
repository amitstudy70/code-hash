// Permutaion - I
class Solution {
public:

    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> temp, unordered_map<int,bool> &mp,int n){

        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int k=0;k<n;k++){
            if(mp[nums[k]]==0){
                temp.push_back(nums[k]);
                mp[nums[k]]=1;
                solve(nums,ans,temp,mp,n);
                temp.pop_back();
                mp[nums[k]]=0;
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=0;
        }
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,ans,temp,mp,nums.size());
        return ans;
    }
};