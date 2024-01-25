#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main() 
{
	srand(time(0));
	double num1 = rand()%101;// cuurent time for random num generation
	cout << " GUESS GAME \n";
	cout << " you have a 5 trials to guess a number \n";
	int x = 1;
	
	while (x <= 5)
	{
		cout << " enter a number : ";
		int num2;
		cin >> num2;
		if (num2 < 0)  //num should be non negative
		{
			cout << "you have entered a negative number\n";
		}

		else if (num2 == num1)  // check for equal numbers
		{

			cout << " Congrats !!  your guess is correct \n";
			break;

		}
		else if (num2 > num1) // check if num is greatwr
		{
			cout << " your guess is to high\n";

			if (num1 > 50 && num1 <= 100) {
				cout << " num is in between 50 -100 \n ";
				continue;
			}

		}
		else if (num2 < num1) // checks if num is lower 
		{

			cout << " your guess is too low \n";
			if (num1 >= 0 && num1 < 50) {
				cout << " num is in between 0 -50\n ";
				continue;

			}

		}
		else 
		{
			cout << " throw an error";
		}

		cout << "\n Try again. You have : " << 5 - x << " trials left.\n";

		x++;
		}
	
	cout <<" so, the num is  : "<< num1;

}