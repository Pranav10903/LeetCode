class Solution {
    public String build(String s){
        Stack<Character>res = new Stack();
        for(char c: s.toCharArray()){
            if(c!='#'){
                res.push(c);
            }
            else if(!res.empty()){
                res.pop();
            }
        }
        return String.valueOf(res);
    }
    public boolean backspaceCompare(String S,String T){
        return build(S).equals(build(T));
    }
}