class Solution {
    public int triangularSum(int[] nums) {
        while(nums.length != 1){
            int[] newNums = new int[nums.length-1];
            for(int i = 0; i < nums.length-1; i++){
                int x = (nums[i] + nums[i+1]) % 10;
                newNums[i] = x;
            }
            nums = newNums;
        }
        return nums[0];
    }
}
