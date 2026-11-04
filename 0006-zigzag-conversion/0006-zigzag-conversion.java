class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1 || numRows >= s.length()){
            return s;
        }

        StringBuilder[] rows = new StringBuilder[numRows];
        for(int i=0;i<numRows;i++){
            rows[i] = new StringBuilder();
        }

        int row = 0;
        int direction = 1;

        for(int i=0;i<s.length();i++){
            rows[row].append(s.charAt(i));

            if(row == 0) direction = 1;
            if(row == numRows-1) direction =-1;

            row+=direction;
        }

        StringBuilder res = new StringBuilder();

        for(int i=0;i<numRows;i++){
            res.append(rows[i]);
        }
        return res.toString();
    }
}