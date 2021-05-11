//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3738/
class Solution {
public:
    
    bool isprime(int n){
        if(n<=1)
            return false;
        if(n==2 || n==3)
            return true;
        if(n%2==0 || n%3==0)
            return false;
        for(int i=5;i*i<=n;i+=6){
            if(n%i==0 || n%(i+2)==0)
                return false;
        }
        return true;
    }
    
    int countPrimes(int n) {
        if(n<=2)
            return 0;
        bool arr[n];
        fill_n(arr,n,1);
        
//In the following loops we are just making false the number that are multiplicative of prime numbers. Rest of the numbers will be the prime numbers.
		
		for(int i=2;i*i<n;i++)  //prime numbers appear only before sqrt(n) 
        {
            if(isprime(i)){ 
                for(int j=i*i;j<n;j+=i){   //making numbers false that are multiples of i.
                    arr[j]=0;
                }
                
            }
        }
        
		int cnt=0;
		
		//iterate through array and count the primes.
        for(int i=2;i<n;i++)
        {
            if(arr[i]==1)
                cnt++;
        }
        return cnt;
    }
};
