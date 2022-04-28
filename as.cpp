#include <iostream>
using namespace std;
int main(){
    cout<<"los numero multiplos de 5, del 1 al 100 es :"<<endl;
    for(int i=1;i<=100;i++){
        if(i%5==0){
            cout<<i<<" ";
        }
    }
}