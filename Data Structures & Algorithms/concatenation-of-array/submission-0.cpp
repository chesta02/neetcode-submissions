class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int s=0;
        int i=0;
        int n=nums.size();
        vector<int>ans;
        while(i<2*n){
            while(i<n && s<n){
                ans.push_back(nums[s]);
                i++;
                s++;
            }
            s=0;
            while(i>=n && s<n){
                ans.push_back(nums[s]);
                i++;
                s++;
            }
            i++;
        }
        return ans;
    }
};