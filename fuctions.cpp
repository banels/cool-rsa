#include <iostream>
#include <random>
#include <stdlib.h>
#include "globals.h"
#include "functions.h"

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
    for (int i = 149; i >= 0; i--){
      random = randomGen();
      primeStrt[i] = random;
      cout << primeStrt[i];
    }
   return true;
}
int mult(int one[], int two[], int arr1_length, int arr2_length){
    for(int i=0;i<arr1_length;i++){
        for(int j=0;j<arr2_length;j++){
            solution[i+j]+=one[i]*two[j];
            solution[i+j+1]=solution[i+j+1]+solution[i+j]/10;
            solution[i+j]%=10;
        }
    }
    return 0;
}
