class Solution {
    public String pushDominoes(String string) {
        char[] dominoes = string.toCharArray();
        int N = dominoes.length;
        int[] forces = new int[N];
        int force = 0;
        for(int i=0;i<N;i++){
            if(dominoes[i]=='R'){
                force = N;
            }
            else if(dominoes[i]=='L'){
                force = 0;
            }
            else{
                force = Math.max(force-1,0);
            }
            forces[i] += force;
        }
        force = 0;
        for(int i=N-1;i>=0;i--){
            if(dominoes[i]=='L'){
                force = N;
            }
            else if(dominoes[i]=='R'){
                force = 0;
            }
            else{
                force = Math.max(force-1,0);
            }
            forces[i] -= force;
        }
        StringBuilder res = new StringBuilder();
        for(Integer f:forces){
            if(f>0){
                res.append('R');
            } else if(f<0){
                res.append('L');
            }
            else{
                res.append('.');
            }
        }
        return res.toString();
    }
}