class Solution {
    public StringBuilder solution(String s, int n) {
        String ans = "";
        StringBuilder a = new StringBuilder();
        for(char c : s.toCharArray()){
            if(c == ' '){
                a.append(' ');
            }else if(Character.isUpperCase(c)){
                a.append((char)((c-'A'+n)%26 + 'A'));
            }else{
                a.append((char)((c-'a'+n)%26 + 'a'));               
            }
        }
        ans = a.toString();
        
        return a;
    }
}