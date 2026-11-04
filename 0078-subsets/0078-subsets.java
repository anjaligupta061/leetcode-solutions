class Solution {
    public void generate(int[] nums, int idx, List<Integer> current, List<List<Integer>> result){
        if(idx == nums.length){
            result.add(new ArrayList<>(current));
            return;
        }
        //exclude
        generate(nums, idx + 1, current, result);
        //include
        current.add(nums[idx]);
        generate(nums, idx + 1, current, result);
        current.remove(current.size()-1);
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        generate(nums, 0, new ArrayList<>(), result);
        return result;
    }
}