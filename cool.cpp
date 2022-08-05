#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <stdio.h>
#include <math.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;


unsigned long long int modular(unsigned long long int base, unsigned long long int exp, int mod) {
   long long res = 1;
   while (exp > 0) {
      if (exp % 2 == 1)
         res= (res * base) % mod;
      exp = exp >> 1;
      base = (base * base) % mod;
   }
   return res;
}

int checkPrime(unsigned long long int value){
    
    bool isPrime = true;

    for (int i = 2; i <= value/2; ++i) {
        if (value % i == 0) {
            isPrime = false;
            break;
        }
    }


    return isPrime;    
}

int getE(unsigned long long int phiOfN){
    int e = 1;
    bool doneFinding = false;

    while (doneFinding == false){
        e++;
        e++;
        if(phiOfN % e > 0){
            doneFinding = true;
        } 
    }
    return e;
}

unsigned long long getD(unsigned long long int phiOfN, int e){
    float d;
    for (int i = 2; i <= e && d != (int)d; i++){
        d = (((2 * phiOfN) + 1)/e);
    }
    return d;
}

int main(){

    srand (time(NULL));
    unsigned long long int bad;
    unsigned int decryptedMesssage;
    unsigned int message = 89;
    unsigned long long int encMessage;
    unsigned long long d;
    unsigned int e;
    unsigned int numOfPrimesDone = 0;
    unsigned int numberOfPrimes = 1;
    unsigned long long int i = (rand() % (rand() % 90 + 100) + 100) * 3;
    unsigned long long int primes[numberOfPrimes];
    unsigned long long int n;
    unsigned long long int phiN;
    while(numOfPrimesDone <= numberOfPrimes && i <= 100000000000000000){
        
        if (checkPrime(i) == true){
            primes[numOfPrimesDone] = i;
            
            cout << primes[numOfPrimesDone] << endl;
            numOfPrimesDone++;// might be a mistake here
        }

        i++;
    }
    primes[0] = 53;
    primes[1] = 59;
    n = primes[0] * primes[1];

    phiN = (primes[0]-1) * (primes[1]-1);

    e = getE(phiN);
    d = getD(phiN, e);

    cout << n << endl;
    cout << phiN << endl;
    cout << e << endl;
    cout << d << endl;

    cout << "message std " << message << endl;
    encMessage = modular(message, e, n);
    cout << "message enc " << encMessage << endl;
    decryptedMesssage = modular(encMessage, d, n);
    cout << "decryption " << decryptedMesssage << endl;



    

    return 0;
}
