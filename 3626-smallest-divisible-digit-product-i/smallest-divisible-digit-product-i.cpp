class Solution {
public:
    int smallestNumber(int n, int t) {
        if(n<=9){
            int p = n;

            while(p%t!=0){
                p++;
                if(p% 10 ==0){
                    return p;
                }
            }
            return p;
        }
        int ans=0;
        if(n % 10==0){
        return n;
        }
        int c = n;
        int b = c % 10;
        c = c/10;
        int a = c %10;
         if( (a * b) % t ==0){
            return n;
         }
         else{
            while((a * b) % t !=0){
                if(b==9){
                    a++;
                    b=0;
                    continue;
                }
                b++;
            }
           ans = (a *10) + b;
         }

        return ans;;
    }
};