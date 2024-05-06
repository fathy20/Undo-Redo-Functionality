#include <iostream>
#include "stack.h"
using namespace std;
short f = 4;
string g = "-1", y;
short x, c = 2, k = 0, a = 0;

void recursion(stack& s, stack& undo) {
   

    cout << " Enter 1 to add number\n";
    cout << " Enter 2 to delete number\n";
    cout << " Enter 3 to display all numbers\n";
    cout << " Enter 4 to undo\n";
    cout << " Enter 5 to redo\n";
    cout << " Enter 0 to exit\n";
    cin >> x;

    if (x == 1) {
        cout << " Enter the number you want to add: ";
        cin >> y;
        s.push(y);
        f = 1;
        g = "2";
        c = 1;
        a = 1;
    }
    else if (x == 2) {
        if (c == 1) {
            g = s.pop();
            f = 0;
            undo.push(g);
        }
        else {
            cout << "First add number\n";
        }
    }
    else if (x == 3) {
        if (g == "-1") {
            cout << "There are no elements\n";
        }
        else {
            s.display();
        }
    }
    else if (x == 4) {
        if (a == 1) {
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
    }
    else if (x == 5) {
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
    }
    else if (x == 0) {
        return;
    }
    else {
        cout << "Enter a number between 0 and 5\n";
    }

    // Recursive call
    recursion(s, undo);
}

