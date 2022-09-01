#include <iostream>
#include <random>
#include<stdlib.h>
#define ll long long
using namespace std;
ll mulmod(ll a, ll b, ll m){//It returns true if number is prime otherwise false {
   ll x = 0,y = a % m;
   while (b > 0) {
      if (b % 2 == 1) {
         x = (x + y) % m;
      }
      y = (y * 2) % m;
      b /= 2;
   }
   return x % m;
}

ll modulo(ll base, ll e, ll m) {
   ll x = 1;
   ll y = base;
   while (e > 0) {
      if (e % 2 == 1)
         x = (x * y) % m;
         y = (y * y) % m;
         e = e / 2;
   }
   return x % m;
}

bool Miller(ll p, int iteration) {
   if (p < 2) {
      return false;
   }
   if (p != 2 && p % 2==0) {
      return false;
   }
   ll s = p - 1;
   while (s % 2 == 0) {
      s /= 2;
   }
   for (int i = 0; i < iteration; i++) {
      ll a = rand() % (p - 1) + 1, temp = s;
      ll mod = modulo(a, temp, p);
      while (temp != p - 1 && mod != 1 && mod != p - 1) {
         mod = mulmod(mod, mod, p);
         temp *= 2;
      }
      if (mod != p - 1 && temp % 2 == 0) {
         return false;
      }
   }
   return true;
}


   


int randomGen(){
    int out;
    uint32_t value; 
    long int valInt;
    std::random_device device;

    value = device();
    valInt = value % 10;
    out = valInt;    
    return out;
}

int main()
{   
   int first_primes_list[70] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                  31, 37, 41, 43, 47, 53, 59, 61, 67,
                  71, 73, 79, 83, 89, 97, 101, 103,
                  107, 109, 113, 127, 131, 137, 139,
                  149, 151, 157, 163, 167, 173, 179,
                  181, 191, 193, 197, 199, 211, 223,
                  227, 229, 233, 239, 241, 251, 257,
                  263, 269, 271, 277, 281, 283, 293,
                  307, 311, 313, 317, 331, 337, 347, 349};
   int primeStrt[150];
   int random = 0;
   bool done = false;
   int arryLoc = 0;
   int carry = 0;
   int solution[151];
   bool extend = false;
   int mult = 2;
   
   for (int i = 149; i >= 0; i--){
      random = randomGen();
      primeStrt[i] = random;
      cout << primeStrt[i];
   }

   
   while(done == false){
      if (arryLoc > 149){
         if (carry != 0){
            extend = true;
            solution[arryLoc] = carry;
            break;
         }
         else {
            extend = false;
            solution[arryLoc] = 0;
            break;
         }
      }
      if (primeStrt[arryLoc] * mult >= 10){
         if (carry != 0){
            solution[arryLoc] = ((primeStrt[arryLoc] * mult) % 10) + carry;
            carry = (((primeStrt[arryLoc] * mult) - ((primeStrt[arryLoc] * mult) % 10)) + carry) / 10;
         }
         else {
            solution[arryLoc] = (primeStrt[arryLoc] * mult) % 10;
            carry = ((primeStrt[arryLoc] * mult) - ((primeStrt[arryLoc] * mult) % 10)) / 10;
         }   
      } 
      else {
         if (carry != 0){
            if ((primeStrt[arryLoc] * mult) + carry >= 10){             
               solution[arryLoc] = (primeStrt[arryLoc] * mult) % 10;
               carry = ((primeStrt[arryLoc] * mult) - ((primeStrt[arryLoc] * mult) % 10)) / 10; 
            }  

            else{
               solution[arryLoc] = (primeStrt[arryLoc] * mult) + carry;
               carry = 0;
            }
            
         }
         else{
            solution[arryLoc] = primeStrt[arryLoc] * mult;
            carry = 0;
         }
      }
      
      arryLoc++;

   }
   
   cout << endl;
   cout << endl;

   if (extend == true){
      for(int i = 150; i >= 0; i--){
         cout << solution[i];
      }
   }
   else{
      for(int i = 150; i >= 1; i--){
         cout << solution[i];
      }
   }
      

    // int iteration = 10;
    // ll num;
    // cout<<"Enter integer to test primality: ";
    // cin>>num;
    // if (Miller(num, iteration))
    //     cout<<num<<" is prime"<<endl;
    // else
    //     cout<<num<<" is not prime"<<endl;




 cout << endl;
 cout << endl;




    return 0;
}
