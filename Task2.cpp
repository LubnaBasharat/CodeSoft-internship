#include <iostream>
using namespace std;

int main()
{
	double num1 = 0;
	double num2 = 0;
	cout << " enter 2 numbers for caculation : \n";
	cin >> num1;
	cin >> num2;
	char choice=0;
	int x = 1;
	if (num1 > 0 && num2 > 0) {
		while (x <= 4) {
			cout << " a: for addition\n";
			cout << " b: for subtraction\n";
			cout << " m: for multiplication\n";
			cout << " d: for division\n";
			cout << " e : for default case \n";
			cin >> choice;
			switch (choice)
			{
			case 'a':
				cout << " number after addition are : " << num1 + num2 << endl;
				break;
			case 'b':
				cout << " numbers after subtraction are : " << num1 - num2 << endl;
				break;
			case 'm':
				cout << " numbers after multiplication are : " << num1 * num2 << endl;
				break;
			case 'd':
				cout << " numbers after division are : " << num1 / num2 << endl;
				break;
			case ' e':
				cout << " error in the program ";
			}
			x++;
		}
	}
	else {
		cout << "there is errror in the program";
	}
}
// lubnaabbasi1213@gmail.com