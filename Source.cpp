#include<iostream>
#include<vector>
#include<string>


class BankAccount
{
private:
	std::string accountNumber;
	double balance;
	std::string accountHolder;

public:
	BankAccount(std::string num, double bal, std::string holder)
	{
		accountNumber = num;
		balance = bal;
		accountHolder = holder;
	}

	void Deposit(double amount)
	{

		try
		{
			if (amount >= 0)
			{
			balance += amount;
			}
			else
			{
			std::cout << "you entered a negative amount" << std::endl;
			}
			std::cout << "Your balance: ";
			std::cout << balance << std::endl;
		}
		catch(...)
		{
			std::cout << "You are trying to deposit an impossible amount to your balance." << std::endl;
		}
	}

	void Withdraw(double amount)
	{
		if (amount < 0)
		{
		std::cout << "It is impossible to withdraw a negative amount from an account" << std::endl;
		return;
		}
		try
		{
			if (balance >= amount)
			{
			balance -= amount;
			std::cout << "Your balance: " << balance << std::endl;
			}
			else
			{
			std::cout << "Your balance: " << balance << std::endl;		
			}

		}
		catch(...)
		{
			std::cout << "You are trying to withdraw an impossible amount to your balance." << std::endl;	
		}
	}


	void GetBalance()
	{
		std::cout << "your balance: " << balance << std::endl;
	}


	void GetAccountHolder()
	{
		std::cout << "Username: " << accountHolder << std::endl;
	}

	void GetAccountNumber()
	{
		std::cout << "Account number: " << accountNumber << std::endl;
	}


	void PrintAccountInfo()
	{
		std::cout << "Username: " << accountHolder << std::endl;
		std::cout << "Account number: " << accountNumber << std::endl;
		std::cout << "your balance: " << balance << std::endl;
	}

};


class Bank
{
private:
        std::vector<BankAccount> accounts;



public:
        void AddAccount(BankAccount account)
        {
                accounts.push_back(account);

        }


        void GetTotalBalance()
        {
                for (BankAccount acc : accounts)
                {
                        acc.GetBalance();
                }
        }

	void PrintAllAccounts()
	{
		for (BankAccount acc : accounts)
		{
			std::cout << "--------------------------------------------------" << std::endl;
			acc.PrintAccountInfo();
		}
	std::cout << " " << std::endl;
	}

};




int main()
{
	
	BankAccount Nashka("123456789", 999, "Nashka");
	BankAccount Pikmi("88005553535", 42, "Pikmi");
	BankAccount Lox("0", 0, "Lox");

	int bal = 0;
	
	Bank MyBank;
	MyBank.AddAccount(Nashka);
	MyBank.AddAccount(Pikmi);
	MyBank.AddAccount(Lox);
	

	MyBank.PrintAllAccounts();


	return 0;

}

