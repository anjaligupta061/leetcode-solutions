class Solution {
    public String[] findWords(String[] words) {
        String row1 = "qwertyuiop";
        String row2 = "asdfghjkl";
        String row3 = "zxcvbnm";

        ArrayList<String> res = new ArrayList<>();

        for(int i = 0;i<words.length;i++){
            String word = words[i].toLowerCase();

            boolean first = true;
            boolean second = true;
            boolean third = true;

            for(int j = 0;j<word.length();j++){
                char ch = word.charAt(j);

                if(row1.indexOf(ch)==-1) first = false;
                if(row2.indexOf(ch)==-1) second = false;
                if(row3.indexOf(ch)==-1) third = false;
            }

            if(first || second || third) res.add(words[i]);
        }

        return res.toArray(new String[0]);
    }
}