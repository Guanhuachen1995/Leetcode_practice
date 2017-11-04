class Solution {
    public boolean judgeCircle(String moves) {
        int ud = 0, lr = 0;
        for(int i = 0; i < moves.length(); i++)
        {
            if(moves.charAt(i) == 'U')
                ud++;
            else if(moves.charAt(i) == 'D')
                ud--;
            else if(moves.charAt(i) == 'L')
                lr++;
            else
                lr--;
        }
        return (ud==0)&&(lr==0); 
    }
}
