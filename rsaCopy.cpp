#include <iostream>
#include <random>
#include <stdlib.h>
#include "globals.h"
// #include "functions.h"


using namespace std;


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

bool randStrt(){
    int random = 0;
    for (int i = primeStrtSize - 1; i >= 0; i--){
      random = randomGen();
      primeStrt[i] = random;
      cout << primeStrt[i];
    }
   return true;
}
int mult(int one[1000], int two[1000], int arr1_length, int arr2_length){
    for(int i=0;i<arr1_length;i++){
        for(int j=0;j<arr2_length;j++){
            solution[i+j]+=one[i]*two[j];
            solution[i+j+1]=solution[i+j+1]+solution[i+j]/10;
            solution[i+j]%=10;
        }
    }
    return 0;
}

int main()
{   
   
   
   cout << "hello" << endl;
   
   
    randStrt();
    for (int i = 0; i <= primeStrtSize - 1; i++){
        prime1[i] = primeStrt[i];
        prime1Size = primeStrtSize;
        
    }   
   
    randStrt();
    for (int i = 0; i <= primeStrtSize - 1; i++){
        prime2[i] = primeStrt[i];
        prime2Size = primeStrtSize;
    }   

    mult(prime1, prime2, prime1Size, prime2Size);

    cout << solution[1] << endl << endl << endl << endl;

    for (int i = 999; i >= 0; i--){
        cout << prime1[i];
    }
    
    cout << endl; 
    
    for (int i = 999; i >= 0; i--){
        cout << prime2[i];
    }
    
    cout << endl; 

    for (int i = 999; i >= 0; i--){
        cout << solution[i];
    }
   
    
    cout << endl; 


 return 0;
}
