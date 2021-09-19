#include <iostream>
#include <vector>
#include "Account.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    int option = 0;
    int *const option_ptr = &option;

    cout << "\n -- WELCOME TO BANKLEDGER --" << endl;

    // Determine user input selection
    while (*option_ptr != 7)
    {
        cout << "\nSelect an option: "
             << "\n1. Open a new account"
             << "\n2. Balance Inquiry"
             << "\n3. Deposit"
             << "\n4. Withdrawl"
             << "\n5. Close an Account"
             << "\n6. Show all Accounts"
             << "\n7. Quit" << endl;
        // Store the input in a pointer
        cin >> *option_ptr;

        switch (*option_ptr)
        {
        case 1:
            Account::open();
            break;
        case 2:
            Account::balance();
            break;
        case 3:
            Account::deposit();
            break;
        case 4:
            Account::withdraw();
            break;
        case 5:
            Account::close();
            break;
        case 6:
            Account::showAll();
        case 7: {
            Account::ledgerDump();
        
            // Delete all vector pointers
            vector<Account *>::iterator itr;
            for ( itr = Account::v_list.begin(); itr != Account::v_list.end(); itr++) {
                delete *itr;
            }

            cout << "Hope to see you soon!" << endl;
            break;
        }
        default:
            cout << "Error: Please enter a valid option (1 - 7)" << endl;
            break;
        }
    }

    delete option_ptr;
    return 0;
}