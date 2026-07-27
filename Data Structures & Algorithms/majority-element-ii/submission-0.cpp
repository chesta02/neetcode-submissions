class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();

        // Count frequency of each element
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        // Find elements occurring more than n/3 times
        for (auto it : mp) {
            if (it.second > n / 3) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};