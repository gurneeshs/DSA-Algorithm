/*
******************** FAST EXPONENTIAN METHOD************************
1. Used to find a^b
2. Runs in O(logb)
3. a^b = (a^(b/2))^2
       = (a^(b/2))^2 * a
4. >>1 = divide by 2
5. var & 1 == (var%2==1)
        
*/
#include <iostream>
using namespace std;
int fastExponentian(int base, int pow, int mod=100){
    int res = 1;
    while(pow>0){
        if(pow & 1){
            res = (res*base);
        }
        base = (base * base);
        pow = pow>>1;
    }
    return res;
}

int main(){
    cout<<"The Value of 2^16 is:"<<fastExponentian(2,16);
}