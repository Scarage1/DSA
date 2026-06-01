#include<iostream>
using namespace std;
 int main(){
    long long n=121, digit, reverse=0;
    cout<< " Shivam"<<endl<<" hey"<<endl;
   while(n>0){
      digit=n%10;
      reverse=reverse*10+digit;
      n=n/10;
   }
    
    if (reverse==121){
        cout<<"palindrome";
    }
    else{
        cout<<"not palindrome";
    }
    
    return 0;
 }