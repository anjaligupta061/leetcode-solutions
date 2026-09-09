class Solution {
    public String frequencySort(String s) {
        HashMap<Character, Integer> freq = new HashMap<>();

        for(char ch : s.toCharArray()){
            freq.put(ch, freq.getOrDefault(ch, 0)+1);
        }

        ArrayList<Map.Entry<Character, Integer>> list = new ArrayList<>(freq.entrySet());

        Collections.sort(list, (a,b)->{
            return b.getValue() - a.getValue();
        });

        StringBuilder ans = new StringBuilder();
        for(Map.Entry<Character, Integer>p : list){
            char ch = p.getKey();
            int count = p.getValue();

            for(int i=0;i<count;i++){
                ans.append(ch);
            }
        }
        return ans.toString();
    }
}