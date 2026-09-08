class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length()!=t.length()) return false;

        int[] v = new int[150];

        for(int i=0;i<v.length;i++){
            v[i] = 1000;
        }
        
        //s->t
        for(int i=0;i<s.length();i++){
            int idx=(int)s.charAt(i);
            if(v[idx]==1000) v[idx]=(s.charAt(i) - t.charAt(i));
            else if(v[idx]!=(s.charAt(i)-t.charAt(i))) return false;
        } 

        //emptying the vector
        for(int i=0;i<150;i++){
            v[i]=1000;
        }

        //t->s
        for(int i=0;i<t.length();i++){
            int idx=(int)t.charAt(i);
            if(v[idx]==1000) v[idx]=(t.charAt(i) - s.charAt(i));
            else if(v[idx]!=(t.charAt(i) - s.charAt(i))) return false;
        }
        return true;
    }
}