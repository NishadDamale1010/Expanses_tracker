#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Expense{
    float amount;
    string category;
    string date;
    string note;

    void input(){
        cout<<"-----Add New Expense -----"<<endl;
        cout<<"Enter your amount :"<<endl;
        cin>>amount;
        cin.ignore(); //clear newline
        cout<<"Enter category of your Expense:"<<endl;
        getline(cin,category);
        cout<<"Enter Date (YYYY-MM-DD):"<<endl;
        getline(cin,date);
        cout<<"Enter Note you want to add :"<<endl;
        getline(cin,note);

    }
};

