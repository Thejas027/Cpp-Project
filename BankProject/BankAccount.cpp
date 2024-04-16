
/*
Application on banking system where it provides some minimal features to it such as
1.Creating account
2.Balance Enquiry
3.Deposit of an amount
4.Withdrwal of an amount
5.To close an account
6.To show all the accounts
7.To Quit
*/

#include <bits/stdc++.h>
using namespace std;

// class which conatains all the necessary members  and methods to create account number
class Account
{
private:
      long accountNumber;
      string firstName;
      string lastName;
      string mailId;
      long phoNum;
      double balance;
      static long nextAccountNum;

public:
      Account(){};                                                            // default constructor
      Account(string firstName, string lastName, string mailId, long phoNum); // parametrised constructor

      // getter methods to get the info of an a bank account holder
      long getAccNo() { return accountNumber; }
      string getFirstName() { return firstName; }
      string getLastName() { return lastName; }
      string getMailId() { return mailId; }
      long getPhoNum() { return phoNum; }
      double getBalance() { return balance; }

      // functions to deposit and withdraw the requried ammount
      void deposit(float amount);
      void withDraw(float amount);

      // getter and setter function to set and get the account number of a account holder in a bank
      void setLastAccNum(long nextAccountNumber);
      long getLastAccNum() { return nextAccountNum; }

      // friend functions which overloads the insertion and extraction operator to customizing the the way of taking input using insertion operator and to output the details as required using extraction operator
      friend ofstream operator<<(ofstream &ofs, Account &acc);
      friend ifstream operator>>(ifstream &ifs, Account &acc);

      // provides the methods to over write the data of various types
      friend ostream operator<<(ostream &ofs, Account &acc);
};

long Account ::nextAccountNum = 0; // since its a static, need to instialzied

// class which contains all the methds to work as realstic
class Bank
{
private:
      map<long, Account> accounts;

public:
      Bank();
      Account openAccount(string firstName, string lastName, string mailId, long phoNum, float balance);
      Account balanceEnquiry(long accountNumber);
      Account deposit(long accountNumber, float amount);
      Account withdraw(long accountNumber, float amount);
      void closeAccoutn(long accountNumber);
      void showAllAccoutn();
      ~Bank();
};

int main()
{
      Bank b;
      Account acc;
      string firstName;
      string lastName;
      string mailId;
      long phoNum;
      float balance;
      float amount;
      int choice;
      do
      {
            cout << "1.To create the new account" << endl;
            cout << "2.To enquiry the balance amount" << endl;
            cout << "3.To deposit the amount to the account" << endl;
            cout << "4.To withdraw the amount from the account" << endl;
            cout << "5.To close the account" << endl;
            cout << "6.To show all accoutn information" << endl;
            cout << "7. To exit the From bank account program" << endl;

            cout << "Enter your choice : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                  break;

            case 2:
                  break;

            case 3:
                  break;
            case 4:
                  break;
            case 5:
                  break;
            case 6:
                  break;

            case 7:
                  cout << "Thank You for visiting the bank account " << endl;
                  break;

            default:
                  cout << "Invalid choice . Please enter the valid choice to get account inforamation " << endl;
                  break;
            }
      } while (choice != 7);
      return 0;
}