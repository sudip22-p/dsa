#include<iostream>
#include<string.h>
using namespace std;
void toh(int n,string s,string a,string d){
    if(n==1){
        cout<<"move disk no."<<n<<" from "<<s<<" to "<<d<<endl;
    } else{
        toh(n-1,s,d,a);
        cout<<"move disk no."<<n<<" from "<<s<<" to "<<d<<endl;
        toh(n-1,a,s,d);
    }
}
int main(){
    int n;
    cout<<"enter the no of disks:";
    cin>>n;
    toh(n,"Source","Helper","Destination");
    return 0;
}