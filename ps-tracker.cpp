#include<iostream>
#include<iomanip>
using namespace std;

string category[5] = {"Food","Clothing","Entertainment","Education","Other"};
string month[12] = {"January","February","March","April","May","June",
"July","August","September","October","November","December"};

double amount[100];
int selectedcategory[100];
int selectedmonth[100];
int n = 0;

void addexpense()
{
    int m, c;
    cout << "\nEnter month (1-12):(january-december): ";
    cin >> m;
    cout << "Enter category (1-5):(food-clothing-entertainment-education-other) ";
    cin >> c;
    cout << "Enter amount: ";
    cin >> amount[n];

    selectedmonth[n] = m - 1;
    selectedcategory[n] = c - 1;
    n++;

    cout << "Expense added!\n";
}

void viewexpenses()
{
    if(n == 0)
    {
        cout << "\nNo expenses found!\n";
        return;
    }

    cout << "\nMonth\t\tCategory\t\tAmount\n";
   
    for(int i = 0; i < n; i++)
    {
        cout << month[selectedmonth[i]] << "\t"
             << category[selectedcategory[i]] << "\t\t"
             << fixed << setprecision(2)
             << amount[i] << "\n";
    }
}
void totalexpenses()
{
    double total = 0;
    for(int i = 0; i < n; i++)
    {
        total += amount[i];
    }
    cout << "\nTotal Expenses: " << fixed << setprecision(2) << total << "\n";
}
int main()
{
    int choice = 0;

    while(choice != 4)
    {
        cout << "\n===== MENU =====";
        cout << "\n1. Add Expense";
        cout << "\n2. View Expenses";
        cout<< "\n3. Total Expenses";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if(choice == 1) addexpense();
        else if(choice == 2) viewexpenses();
        else if(choice == 3) totalexpenses();
        else if(choice == 4) cout << "Exiting...\n";
        else cout << "Invalid choice!\n";
    }

    return 0;
}