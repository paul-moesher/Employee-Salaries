//----------------------------------------------------------------------------------------------------------------------------------------------------------
// Paul Moesher												 CS2010														 MWF 10:30
//-----------------------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Functions
void readSalaries(double[],int);
void displaySalaries(double[], int);
void payRaise(double[], int);
void totalSalaries(double[], int);

int main()
{

	// Declare variables 

	int size = 12; // The amount size of the array and the amount of salaries in the txt file

	// Declare array

	double salaries[12];

	// Call readSalaries function

	readSalaries(salaries, size);

	// State that the oringial salaries from the txt file will show

	cout << "\n Orinigal salaries" << endl;

	// Call the displaySalaries function

	displaySalaries(salaries, size);

	// Call the payRaise function

	payRaise(salaries, size);

	// State that the salaries after the pay raise are about to be displayed

	cout << "\n Salaries after payRise" << endl;

	// Call the displaySalaries function

	displaySalaries(salaries, size);

	// Call the totalSalaries function

	totalSalaries(salaries, size);

	cout << endl;
	system("pause");
	return 0;


}

void readSalaries(double salaries[],int size)  // Note to self this I think this is the best/easiest way to write a function that pulls data from a txt file
{

	ifstream inFile;

	inFile.open("lab11.txt");

	if (inFile.is_open())

	{

		int i = 0;

		// read till the end of the file and upto 12 salaries

		while (!inFile.eof() && i<size)
		{

			inFile >> salaries[i];

			i++;

		}

	}
	else

		cout << "\n Unable to open file ";

	inFile.close();

}

	// function to display the salaries

	void displaySalaries(double salaries[], int size)

	{

		for (int i = 0; i<size; i++)

			cout << "$" << salaries[i] << endl;

	}

	// function to increase the salary by 3 percent

	void payRaise(double salaries[], int size)

	{

		for (int i = 0; i<size; i++)

			salaries[i] = salaries[i] + 0.03*salaries[i];

	}

	// function to calculate the total salary for Cleveland and Cincinnati employees and total salary

	// Cleveland employees salary are stored at index 0,2,4,etc and Cincinnati employees salary are stored at index 1,3,5,etc

	void totalSalaries(double salaries[], int size)

	{

		double totalCleveland = 0, totalCincinnati = 0, total = 0;

		for (int i = 0; i<size; i++) {

			if (i % 2 == 0)

				totalCleveland += salaries[i];

			else

				totalCincinnati += salaries[i];

			total += salaries[i];

		}

		cout << "\n Total salaries for Cleveland employees = $" << fixed << setprecision(2) << left << totalCleveland << endl;

		cout << " Total salaries for Cincinnati employees = $" << fixed << setprecision(2) << left << totalCincinnati << endl;

		cout << " Total salaries for all employees = $" << fixed << setprecision(2) << left << total << endl;

	}
	