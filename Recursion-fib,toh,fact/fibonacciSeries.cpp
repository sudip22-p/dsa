#include<iostream>
using namespace std;
int fibo(int n){
    if(n==1){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    else{
        return fibo(n-2)+fibo(n-1);
    }
}
int main(){
    int n;
    cout<<"enter the number of terms of fibonacci series to display:"<<endl;
    cin>>n;
    cout<<"The fibonacci series upto n terms are as follows:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<" "<<fibo(i)<<" ";
    }
    cout<<endl;
    return 0;
}