class Solution {
    public int largestPerimeter(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        if(n <= 2){
            return 0;
        }
        int i = n-1, j = n-2, k = n-3;
        while(k >= 0){
            int a = nums[i], b = nums[j], c = nums[k];
            if(a + b > c && b + c > a && c + a > b){
                return a + b + c;
            }
            i--;
            j--;
            k--;
        }
        return 0;
    }
}
