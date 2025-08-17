#include<iostream>
using namespace std;

class Shop{
    int itemId[100];
    int itemPrice[100];
    int i;  //counter
    public:
        void initi(){  //initializing i
            i=0;
        }  
        void setPrice();
        void getPrice();
};

void Shop :: setPrice(){
    cout<<"enter the id of item number "<<i+1<<" : ";
    cin>>itemId[i];
    cout<<"enter the price of item : ";
    cin>>itemPrice[i];
    i++;
}

void Shop :: getPrice(){
    for (int j=0;j<i;j++){
        cout<<"price of itemid "<<itemId[j]<<"is "<<itemPrice[j]<<endl;
    }
}
int main(){
    Shop dukaan;
    dukaan.initi();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.getPrice();
    return 0;
}