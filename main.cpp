#include <iostream>
#include <string>
using namespace std;
string SignedIntegerToSignMagnitude(int num) {
    long long tmp = 1 << 7;
    if(num < -tmp + 1 || num > tmp - 1) return "overflow";
    if(num == 0)
    return "10000000 00000000";
    int sign = (num < 0) ? 1 : 0;
    int magnitude = (num < 0) ? -num : num;

    // Convert the magnitude to binary and pad to 7 bits
    string magnitudeBits;
    for (int i = 6; i >= 0; i--) {
        magnitudeBits += (magnitude & (1 << i)) ? '1' : '0';
    }

    // Combine the sign bit and magnitude bits
    string SignMagnitude = to_string(sign) + magnitudeBits;

    return SignMagnitude;
}
string SignedIntegerToOneComplement(int num) {
    long long tmp = 1 << 7;
    if(num < -tmp + 1 || num > tmp - 1) return "overflow";
    if(num == 0)
    return "11111111 00000000";
    int sign = (num < 0) ? 1 : 0;
    int magnitude = (num < 0) ? -num : num;

    // Convert the magnitude to binary and pad to 7 bits
    string magnitudeBits;
    for (int i = 6; i >= 0; --i) {
        if(sign == 0)
        magnitudeBits += (magnitude & (1 << i)) ? '1' : '0';
        else magnitudeBits+= (magnitude & (1 << i)) ? '0' : '1';
    }

   
    
    // Combine the sign bit and inverted magnitude bits
    string oneComplement = to_string(sign) + magnitudeBits;

    return oneComplement;
}
int main() {
    int num;
    cin>>num;
    cout<<"Output a: "<<SignedIntegerToSignMagnitude(num)<<endl;
    cout<<"Output b: "<<SignedIntegerToOneComplement(num);

    return 0;
}
