//Single Element in a sorted array
//Link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/
class Solution {
public:
    int singleNonDuplicate1(vector<int>& nums, int low,int high) {
        
        int mid = (low+high)/2;
        if(high == low){return nums[mid];}
        if(mid ==0){return nums[mid];}
        if(mid==nums.size()-1){return nums[mid];}
        if(mid%2==0){
            while(high>low){
                if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                    return nums[mid];
                }else if(nums[mid]==nums[mid+1]){
                    
                    return  singleNonDuplicate1(nums,mid+1, high);
                }else {
                    return singleNonDuplicate1(nums,low,mid-1);
        }   }   }
        
        else{
            while(high>=low){
                if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                    return nums[mid];
                }else if(nums[mid]==nums[mid+1]){
                    
                    return  singleNonDuplicate1(nums,low, mid-1);
                }else {
                    return singleNonDuplicate1(nums,mid+1, high);
        }   }   }



        return 0;

        
    }

    int singleNonDuplicate(vector<int>& nums){
        int sizee = nums.size();
        return singleNonDuplicate1(nums, 0, sizee-1);
    }
};