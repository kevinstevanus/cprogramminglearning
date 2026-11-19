#ifndef ACCOUNT_H
#define ACCOUNT_H

// there is a struct called account, trust me.
typedef struct Account Account;

// the only ways 3rd parties are allowed to interact with an account;
Account *account_open(int initial_deposit);
void account_deposit(Account *acc, int amount);
int account_get_balance(const Account *acc);
void account_close(Account *acc);

#endif
