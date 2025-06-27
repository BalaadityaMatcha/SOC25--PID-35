class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        if(n==3) return 1;
        int size = ( n%2 ? (n-3)/2 : (n-3)/2 + 1);
        vector<bool> p(size,false);
        int nprimes = 1;
        for(int i=0;i<size;i++){
            if(p[i]) continue;
            else{
                nprimes++;
                int pr = 2*i + 3;
                for(long long k=(1LL*pr*pr - 3)/2;k<size;k+=pr){
                    p[k]=true;
                }
            }
        }
        return nprimes;
    }
};