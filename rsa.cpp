#include <iostream>
#include <random>
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

int main()
{  
    int primeStrt[150];
    int random = 0;
    for (int i = 0; i <= 150; i++){
        random = randomGen();
        primeStrt[i] = random;
        cout << primeStrt[i] << ", " ;
    }
    return 0;
}
