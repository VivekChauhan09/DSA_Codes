#include<iostream>
using namespace std;

class student{
    string name; //this data member is defined in private

    public:
    int age;    
    string gender;
    //to access the name data member
    void setname(string s){
        name=s;
    }
    //to print the value we will write a function within the class 
    void printinfo(){
        cout<<"name is "<<name<<endl;
        cout<<"age is "<<age<<endl;
        cout<<"gender is "<<gender<<endl;

    }
};

int main(){
    int n,i=0;
    cout<<"enter the number of data:";
    cin>>n;
    student stud[n];
    cout<<"enter the data\n";
    for (i=0;i<n;i++){
        string s;
        cout<<"enter the name of students:";
        cin>>s;
        stud[i].setname(s);
        cout<<"enter the age of students:";
        cin>>stud[i].age;
        cout<<"enter the gender of students:";
        cin>>stud[i].gender;
    }
    for(i=0;i<n;i++){
        stud[i].printinfo();
    }
    return 0;
}