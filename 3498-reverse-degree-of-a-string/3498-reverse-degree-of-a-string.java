class Solution {
    public int reverseDegree(String s) {
        int n = s.length();
        if(s == "") return 0;
        HashMap<Character, Integer> map = new HashMap<>();
        for(char ch = 'a';ch<='z';ch++){
            map.put(ch, 26-(ch-'a'));
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            char ch = s.charAt(i);
            sum += (map.get(ch)*(i+1));
        }
        return sum;
    }
}