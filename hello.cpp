#include <iostream>
using namespace std;
/*int main(){
    int x,a,count=0;
    cout << "Enter a numebr : ";
    cin >> x;
    while(x!=0){
        a = x % 10;
        x=x/10;
        cout << a <<endl;
        count++;
    }
    cout << "Digits : "<< count;
}*/
/*
read -p "Enter a number: " x;
for (( ; x != 0 ; ))
do
    a=$(( x % 10 ))
    x=$(( x / 10 ))
    echo $a
    ((count++))
done
echo "Digits : $count"
*/
int main(){
    int x;
    cout << "Enter a number : ";
    cin >>x;
    for(int i = 0 ; i < x ; i ++){
        for(int j = 0 ; j <= i ; j++){
            cout << i << " ";
        }
        cout << endl;
    }
    for(int i = x - 1 ; i > 0 ; i -- ){
        for(int j = 0 ; j < i ; j++){
            cout << "*";
        }
        cout << endl;
    }
}