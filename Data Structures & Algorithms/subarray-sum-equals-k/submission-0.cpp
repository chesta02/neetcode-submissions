class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count=0;
        int curr=0;
        mp[0]=1;
        for(int val:nums){
            curr+=val;
            if(mp.find(curr-k)!=mp.end()){
                count+=mp[curr-k];
            }
            mp[curr]++;
        }
        return count;
    }
};