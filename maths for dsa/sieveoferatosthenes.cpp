/*
****************SIEVE OF ERATOSTHENES*************************
To count the prime numbers upto n
Initially mark all the prime numbers prime. 
Then IF a number is prime, the all the numbers in its table are not 
prime
Time Complexity: O(n*log(log n))

*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,cnt=0;
    cout<<"Enter n:";
    cin>>n;

    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;

    for(int i = 2; i<n;i++){
        if(prime[i]){
            cnt++;
        }
        for(int j=2*i;j<n;j=j+i){
            prime[j] = false;
        }
    }
    cout<<"Number of Prime numbers upto n are:"<<cnt;
    return 0;
}