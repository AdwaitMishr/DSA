class Solution {
public:
    bool isPalindrome(int x) {
        int x1=x;
        if(x<0){return 0;}
        long long dup=0;
        while(x!=0){
            dup=dup*10+x%10;
            x=x/10;
        }
        return (dup==x1);
    }
};