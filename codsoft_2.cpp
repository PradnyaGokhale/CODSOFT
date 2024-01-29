#include <iostream>
using namespace std;

int main() {
    int num;
    double x,y;
    cout<<"\t\t\t\t\t\t\tCALCULATOR"<<endl;
    
    do {
        cout<<"Enter the number to perform following tasks: \n1. Addition \n2. Subtraction \n3. Multiplication \n4. Division \n5. Exit"<<endl;
        cin>>num;
        
        switch(num) {
            case 1: cout<<"Addition"<<endl;
            cout<<"Enter the addends: "; /*Addends are the numbers to be added.*/
            cin>>x>>y;
            cout<<x+y<<endl;
            break;
            case 2: cout<<"Subtraction"<<endl;
            cout<<"Enter the minuend: "; /*Minuend is the number from which other number is subtracted.*/
            cin>>x;
            cout<<"Enter the subtraend: "; /*Subtraend is the number which is subrtacted from other number.*/
            cin>>y;
            cout<<x-y<<endl;
            break;
            case 3: cout<<"Multiplication"<<endl;
            cout<<"Enter the multiplicand: "; /*Multiplicand is the number which is to be multiplied.*/
            cin>>x;
            cout<<"Enter the multiplier: "; /*Multiplier is the number by which the multiplicand is multiplied.*/
            cin>>y;
            cout<<x*y<<endl;
            break;
            case 4: cout<<"Division"<<endl;
            cout<<"Enter the dividend: "; /*Dividend is the number which is to be divided.*/
            cin>>x;
            cout<<"Enter the divisor: "; /*Divisor is the number by which the dividend is divided.*/
            cin>>y;
            cout<<x/y<<endl;
            break;
            case 5: cout<<"End of the Program."<<endl;
            break;
            default: cout<<"Invalid Choice."<<endl;
            break;
        }
    }while(num!=5);

    return 0;
}