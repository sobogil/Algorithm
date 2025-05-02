class Solution {
    public int solution(int a, int b, int n) {
        int ans = 0;
        int remain=0;
        while(n >= a){
            ans += b*(n/a);
            int temp = b*(n/a);
            remain = n%a;
            n=0;
            n += remain;
            n += temp;
        }
        
        return ans;
    }
}