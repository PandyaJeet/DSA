#include <iostream>
using namespace std;
int gcd(int a , int b){
    if (b!=0){
    int temp = b;
    b=a%b;
    a = temp;
    return gcd(a, b);
}
    return a;
}
/*int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}*/
int main(){
    int a,b;
    cout << "Enter 2 integers : \n";
    cin >> a >> b;
    if(a>b)
    cout << "GCD is : " << gcd(a,b) << endl;
    else 
    cout << "GCD is : " << gcd(b,a)<< endl;
    //cout << "LCM is : " << lcm(a,b);
}