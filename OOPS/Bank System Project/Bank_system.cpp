#include <iostream>
using namespace std;
// Requirements: Classes for Account, SavingsAccount, CurrentAccount. 
// Use virtual functions for calculating interest.

class Account
{
    protected:
        int balance;
    public:
        float interestrate,interest_ammount;
        string name_acc,name_bank,benificiary;
        Account(string s,string b)
        {
            name_acc=s;
            name_bank=b;
            balance=0;
            interestrate=0;
        }
        virtual void interestc(int years)
        {
            interest_ammount=(interestrate*balance*years)/100;
            cout<<"Interset is "<<interest_ammount<<endl;
        }
        void credit(int money)
        {
            // cout<<"Enter the amount to be credited in account:";
            // cin>>money;
            balance+=money;
            cout<<"Now your balance is "<<balance<<endl;
        }
        void debit(int money)
        {
            // cout<<"Enter the amount to be debited in account:";
            // cin>>money;
            if(money>balance)
            {
                cout<<"Amount entered is larger than the current balance.\nSo amount can't be debited.\n";
            }
            else
            {
                balance-=money;
                cout<<"Now your balance is "<<balance<<endl;
            }
            
        }
        virtual ~Account() {}
};

class SavingsAccount : public Account
{
    private:
        string savings_account_ID;

    public:
        SavingsAccount(string s,string b) : Account(s, b)
        {
            interestrate=5.0;
        }

        void getfetch_id()
        {
            cout<<savings_account_ID;
        }

        void interestc(int years) override
        {
            interest_ammount=(interestrate*balance*years)/100;
            cout<<"Interset is "<<interest_ammount<<endl;
        }
};

class CurrentAccount : public Account
{
    private:
        string Current_account_ID,Type;

    public:
        CurrentAccount(string s,string b): Account(s, b)
        {
            interestrate=2.0;
        }

        void getfetch_id()
        {
            cout<<Current_account_ID;
        }

        void interestc(int years) override
        {
            interest_ammount=(interestrate*balance*years)/100;
            cout<<"Interset is "<<interest_ammount<<endl;
        }
};

int main()
{
    SavingsAccount sa("Rushabh", "SBI");
    sa.credit(10000);
    sa.interestc(2);

    CurrentAccount ca("Pandya", "HDFC");
    ca.credit(20000);
    ca.interestc(1);

    return 0;
}
