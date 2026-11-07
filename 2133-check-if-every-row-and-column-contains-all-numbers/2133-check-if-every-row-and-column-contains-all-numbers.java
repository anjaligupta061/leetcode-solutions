class Solution {
    public boolean checkValid(int[][] matrix) {
        int n = matrix.length;

        for(int i=0;i<n;i++){
            boolean[] row = new boolean[n+1];
            boolean[] col = new boolean[n+1];
            for(int j=0;j<n;j++){
                int r = matrix[i][j];
                int c = matrix[j][i];

                if(r<1 || r>n || row[r]) return false;

                row[r] = true;

                if(c<1 || c>n || col[c]) return false;

                col[c] = true;
            }
        }
        return true;
    }
}