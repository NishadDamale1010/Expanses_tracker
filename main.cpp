#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
class Expense
{
public:
    float amount;
    string category;
    string date;
    string note;

    void input()
    {
        cout << "-----Add New Expense -----" << endl;
        cout << "Enter your amount :" << endl;
        cin >> amount;
        cin.ignore(); // clear newline
        cout << "Enter category of your Expense:" << endl;
        getline(cin, category);
        cout << "Enter Date (YYYY-MM-DD):" << endl;
        getline(cin, date);
        cout << "Enter Note you want to add :" << endl;
        getline(cin, note);
    }
    void display(int index) const
    {
        cout << index + 1 << "." << date << "|$" << amount << "|" << category << "|" << note << endl;
    }

    void saveToFile()
    {
        ofstream out("expenses.txt", ios::app); // append mode
        if (out.is_open())
        {
            out << date << "|" << category << "|" << amount << "\n";
            out.close();
        }
        else
        {
            cout << "Error opening file for writing!\n";
        }
    }
};
vector<Expense> expenses; // To store expenses

int main()
{
    while (true)
    {
        int ch;
        cout << "\n===== Expense Tracker =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View All Expenses\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        cin.ignore();
        switch (ch)
        {
        case 1:
        { // non-trivial declarations
            Expense e;
            e.input();
            expenses.push_back(e);
            e.saveToFile();
            expenses.push_back(e);
            cout << "Expenses added successfully!!" << endl;
            break;
        }
        case 2:
        {
            if (expenses.empty())
            {
                cout << "No expenses recorded yet!" << endl;
            }
            else
            {
                for (int i = 0; i < expenses.size(); ++i)
                {
                    expenses[i].display(i);
                }
            }
            break;
        }
        case 3:
        {
            cout << "Exiting Expanse Tracker , Thanks for visiting " << endl;
            return 0;
        }
        default:
            cout << " Invalid choice. Try again.\n";
        }
    }
    return 0;
}