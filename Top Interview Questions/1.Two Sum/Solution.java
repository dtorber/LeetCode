class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> ajuda = new HashMap<Integer, Integer>(); //index -> diferència
        int[] solucio = new int[2];
        for (int i = 0; i < nums.length; i++) {
            int aux = target - nums[i];
            if (ajuda.get(aux) != null) {
                solucio[0] = ajuda.get(aux);
                solucio[1] = i;
                break;
            } else {
                ajuda.put(nums[i], i);
            }
        }
        return solucio;
    }
}