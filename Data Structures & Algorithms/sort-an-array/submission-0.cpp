class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }

    void mergesort(vector<int>&nums,int left,int right){
        if(left>=right) return;

        int mid=left+(right-left)/2;
        mergesort(nums,left,mid);
        mergesort(nums,mid+1,right);
        merge(nums,left,right,mid);
    }
    void merge(vector<int>&nums,int left,int right,int mid){
        vector<int>temp;
        int i=left;
        int j=mid+1;
        while(i<=mid && j<=right){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid) temp.push_back(nums[i++]);
        while(j<=right) temp.push_back(nums[j++]);

        for(int k=0;k<temp.size();k++){
            nums[left+k]=temp[k];
        }
    }
};