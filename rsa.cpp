#include <iostream>
#include <random>
using namespace std;
long int randomGen(){
    long int out;
    uint32_t value; 
    long int valInt;
    std::random_device device;

    value = device();
    valInt = value;
    out = valInt;    
    return out;
}
int main()
{  
    for (int i = 0; i <= 100; i++){
        cout << randomGen() << endl;
    }
}
