#include <iostream>
#include "stack.h"
using namespace std;
short f = 4;//to check the last operation add or delete to undo it ,it is value change when add or delete 
string  y;//variable to push when use add
short number,  k = 0;

void recursion(stack& s, stack& undo) {
    cout << " Enter 1 to add number\n";
    cout << " Enter 2 to delete number\n";
    cout << " Enter 3 to display all numbers\n";
    cout << " Enter 4 to undo\n";
    cout << " Enter 5 to redo\n";
    cout << " Enter 0 to exit\n";
    cin >> number;

    switch (number) {
    case 1:
        cout << " Enter the number you want to add: ";
        cin >> y;
        s.push(y);
        f = 1;
        
        
        
        break;
    case 2:
        if (!s.is_empty()) {
            
            f = 0;
            undo.push(s.pop());
        }
        else {
            cout << "First add number\n";
        }
        break;
    case 3:
        if (s.is_empty()) {
            cout << "There are no elements\n";
        }
        else {
            s.display();
        }
        break;
    case 4:
        if (!s.is_empty()) {
            k = 1;
            if (f == 1) {
                undo.push(s.pop());
            }
            else {
                s.push(undo.pop());
            }
        }
        else {
            cout << "Add a number first\n";
        }
        break;
    case 5:
        if (k == 1) {
            if (!undo.is_empty()) {
                s.push(undo.pop());
                f = 1;
            }
            else {
                cout << "No operations to redo\n";
            }
        }
        else {
            cout << "Use undo first\n";
        }
        break;
    case 0:
        return;//recursion break
    default:
        cout << "Enter a number between 0 and 5\n";
    }

    // Recursive call
    recursion(s, undo);
}
