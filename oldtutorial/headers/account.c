#include "account.h"
#include <stdlib.h>

struct Account {
  int balance;
};

Account *account_open(int initial_deposit) {
  Account *acc = malloc(sizeof(Account));
  acc->balance = initial_deposit;
  return acc;
}

void account_deposit(Account *acc, int amount) {
  if (amount > 0) {
    acc->balance += amount;
  }
}

int account_get_balance(const Account *acc) { return acc->balance; }

void account_close(Account *acc) { free(acc); }
