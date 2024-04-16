
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
#define MIN_BALANCE 500
using namespace std;

// class which throws exception
class InsufficientFunds
{
};

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
        Account(){};                                                                           // default constructor
        Account(string firstName, string lastName, string mailId, long phoNum, float balance); // parametrised constructor

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
        friend ofstream &operator<<(ofstream &ofs, Account &acc);
        friend ifstream &operator>>(ifstream &ifs, Account &acc);

        // provides the methods to over write the data of various types
        friend ostream &operator<<(ostream &os, Account &acc);
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
        long accountNumber;
        string firstName;
        string lastName;
        string mailId;
        long phoNum;
        float balance;
        float amount;
        int choice;
        do
        {
                cout << "Welcome to our banking system. What are you looking for," << endl;
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
                        cout << endl
                             << "Enter the necesarry information to create the account in our bank" << endl;
                        cout << "Enter the first name of the account holder :";
                        cin >> firstName;
                        cout << "Enter the last name of the accoutn holder : ";
                        cin >> lastName;
                        cout << "Enter the mail id of the account holder : ";
                        cin >> mailId;
                        cout << "Enter the phone number of a account holder : ";
                        cin >> phoNum;
                        cout << "Enter the balance ammount to be show or to hold in a acccount : ";
                        cin >> balance;

                        acc = b.openAccount(firstName, lastName, mailId, phoNum, balance);

                        cout << endl
                             << "Congulatations you have sucessfully created the account " << endl;
                        cout << acc;
                        break;

                case 2:
                        break;

                case 3:
                        cout << "Enter the account number to deposited the ammount : ";
                        cin >> accountNumber;
                        cout << "Enter the amount to be deposied : ";
                        cin >> amount;
                        acc = b.deposit(accountNumber, amount);
                        cout << endl
                             << amount << " deposited to the account number ->  " << accountNumber << endl;
                        cout << acc;
                        break;

                case 4:
                        cout << "Enter the account number to withdraw the amount : ";
                        cin >> accountNumber;
                        cout << "Enter the amount to be withdrawan from the account : ";
                        cin >> amount;
                        acc = b.withdraw(accountNumber, amount);
                        cout << endl
                             << amount << "has been withdrawan from the account ->" << accountNumber << endl;
                        cout << acc;
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

// decalration of methods of a predefined classes in a account class

// parametrized constructor declaration
Account ::Account(string firstName, string lastName, string mailId, long phoNum, float balance)
{
        nextAccountNum++;
        accountNumber = nextAccountNum;
        this->firstName = firstName;
        this->lastName = lastName;
        this->mailId = mailId;
        this->phoNum = phoNum;
        this->balance = balance;
}

// method to deposit the amount
void Account ::deposit(float amount)
{
        balance += amount;
}

// method to withdraw the amount
void Account ::withDraw(float amount)
{
        if (balance - amount < MIN_BALANCE)
                throw InsufficientFunds();
        balance -= amount;
}

// setter and getter method to set and get that account number
void Account::setLastAccNum(long accountNum)
{
        nextAccountNum = accountNum;
}
long Account ::getLastAccNum()
{
        return nextAccountNum;
}

ofstream &operator<<(ofstream &ofs, Account &acc)
{
        ofs << acc.accountNumber << endl;
        ofs << acc.firstName << endl;
        ofs << acc.lastName << endl;
        ofs << acc.mailId << endl;
        ofs << acc.phoNum << endl;
        ofs << acc.balance << endl;
        return ofs;
}

ifstream &operator>>(ifstream &ifs, Account &acc)
{

        ifs >> acc.accountNumber;
        ifs >> acc.firstName;
        ifs >> acc.lastName;
        ifs >> acc.mailId;
        ifs >> acc.phoNum;
        ifs >> acc.balance;
        return ifs;
}

ostream &operator<<(ostream &os, Account &acc)
{
        os << "First Name : " << acc.getFirstName() << endl;
        os << " Last Name : " << acc.getLastName() << endl;
        os << " Mail Id : " << acc.getMailId() << endl;
        os << "Phone Number : " << acc.getPhoNum() << endl;
        os << "Balance : " << acc.getBalance() << endl;
        return os;
}