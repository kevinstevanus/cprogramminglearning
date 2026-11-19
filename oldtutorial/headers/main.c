#include "account.h"
#include <stdio.h>

int main(void) {
  Account *my_acc = account_open(100);

  // account_deposit(my_acc,100, int amount)
  account_deposit(my_acc, 50);

  printf("Balance: %d\n", account_get_balance(my_acc));

  account_close(my_acc);
  return 0;
}
