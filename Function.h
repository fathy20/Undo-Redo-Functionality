# include <iostream>
#include"stack .h"
using namespace std;
void recurion()
{
	stack s, undo;//2stack the second  one to store undo elements 
	int x = 5, y, f, g, k = 0;// f to control undo if f=1 he added number before if zero the user deleted number 
	//g to control negative 1 in header stack pop ; k to control redo redo work if he used undo before 
	while (x > 0) {
		cout << " Enter 1  to add number  " << "\n";
		cout << " Enter 2  to delete number  " << "\n";
		cout << " Enter 3  to display all numbers  " << "\n";
		cout << " Enter 4  to  undo   " << "\n";
		cout << " Enter 5  to  redo   " << "\n";
		cout << " Enter 0  to  exit   " << "\n";
		cin >> x;
		if (x == 1) {
			cout << " Enter the number you want  to add  : " << "\n";
			cin >> y;
			s.push(y);
			f = 1;
			g = 2;
		}
		else if (x == 2)
		{
			g = s.pop(); f = 0;
			undo.push(g);
		}
		else if (x == 3) {
			if (g == -1)
			{
				cout << " There is no elements";

			}
			else s.display();
		}
		else if (x == 4) {
			k = 1;
			if (f == 1) {
				undo.push(s.pop());
			}
			else {
				s.push(undo.pop());
			}
		}
		else if (x == 5) {
			if (k == 1) {
				s.push(undo.pop());
			}
			else
				cout << " Use undo first" << "\n";
		}
		else if (x == 0)
			break;
		else cout << ("Enter number between 0 and 5");
	}
}
