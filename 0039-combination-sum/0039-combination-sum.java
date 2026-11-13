class Solution {
    public void findCombinations(int idx, int[] arr, int target, List<List<Integer>> ans, List<Integer> ds){
        if(idx == arr.length){
            if(target == 0){
                ans.add(new ArrayList<>(ds));
            }
            return;
        }

        //pick
        if(arr[idx] <= target){
            ds.add(arr[idx]);
            findCombinations(idx, arr, target - arr[idx], ans, ds);
            ds.remove(ds.size() - 1);
        }

        //skip
        findCombinations(idx + 1, arr, target, ans, ds);
    }
    public List<List<Integer>> combinationSum(int[] arr, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        findCombinations(0, arr, target, ans, new ArrayList<>());
        return ans;
    }
}