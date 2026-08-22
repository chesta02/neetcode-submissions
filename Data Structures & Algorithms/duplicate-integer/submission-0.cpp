class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int val:nums){
            if(mp.find(val)!=mp.end()){
                return true;
            }
            mp[val]++;
        }
        return false;
        
    }
};