#include <iostream> // To use cin/cout
#include <iomanip> // Manipulate output with setw, setprecision

using namespace std;

// Monthly payment rates
const int STAN_MONTH_RATE = 12, PREM_MONTH_RATE = 25;
const int STAN_MAX = 60, PREM_DAY_MAX = 75, PREM_NIGHT_MAX = 100;

const string COL_DIVIDER = "  |  ";

// Standard min rate occurs after 60 min
// Premium rate1 for daytime min: 7:00AM to 7:00PM (after 75 min)
// Premium rate2 for nightime min: 7:01 PM to 6:59 AM (after 100 min)
const double STAN_MIN_RATE = 0.20, PREM_DAY_RATE = 0.10, PREM_NIGHT_RATE = 0.05;

int main()
{
	int dayMin, nightMin, totalMin = 0;
	double totalBill = 0, dayFee = 0, nightFee = 0;
	string accountNum, serviceType, sectionBreak, colDivider;
	char planType;

	while (sectionBreak.length() < 30)
	{
		sectionBreak += "-";
	}

	cout << "Phone Plan Calculator Program" << endl
		<< "By Forrest Moulin" << endl << endl
		<< "Please enter your account number, followed by" << endl
		<< "a space and your service plan type." << endl
		<< "(S for Standard or P for Premium)" << endl << endl;

	cin >> accountNum >> planType;

	cout << endl << "Thank you! Now, please enter the ";

	// Standard plan selection logic
	if (planType == 'S' || planType == 's')
	{
		serviceType = "Standard";
		cout << endl << "total minutes used during the billing cycle."
			<< endl << "Be sure to use an integer." << endl << endl;

		// Get total minutes from user
		cin >> totalMin;

		// Calculate standard bill
		totalBill += STAN_MONTH_RATE;
		if (totalMin > STAN_MAX)
		{
			totalBill += (totalMin - STAN_MAX) * STAN_MIN_RATE;
		}
	}
	// Premium plan selection logic
	else if (planType == 'P' || planType == 'p')
	{
		serviceType = "Premium";
		cout << endl << "number of daytime and nighttime minutes" << endl
			<< "separated by a space." << endl
			<< "Be sure to enter daytime minutes first."
			<< endl << endl;

		// Get day and night minutes from user
		cin >> dayMin >> nightMin;
		totalMin = dayMin + nightMin;

		// Calculate premium bill
		totalBill += PREM_MONTH_RATE;
		if (dayMin > PREM_DAY_MAX)
		{
			dayFee = (dayMin - PREM_DAY_MAX) * PREM_DAY_RATE;
			totalBill += dayFee;
		}
		if (nightMin > PREM_NIGHT_MAX)
		{
			nightFee = (nightMin - PREM_NIGHT_MAX) * PREM_NIGHT_RATE;
			totalBill += (nightMin - PREM_NIGHT_MAX) * PREM_NIGHT_RATE;
		}
	}

	// Print table to console (width 30 char)
	// Column1 width set to 21 char
	cout << endl << "Forrest's Green Cell Phone Co." << endl
		<< sectionBreak;
	cout << fixed << setprecision(2) << endl
		<< left << setw(21) << "Account number:" << accountNum << endl
		<< left << setw(21) << "Service type:" << serviceType << endl;
	if (serviceType == "Premium")
	{
		cout << left << setw(21) << "Daytime minutes:" << dayMin << endl
			<< left << setw(21) << "Daytime fee:" << "$" << dayFee << endl
			<< left << setw(21) << "Nighttime minutes: " << nightMin << endl
			<< left << setw(21) << "Nighttime fee:" << "$" << nightFee << endl;
	}
	cout << left << setw(21) << "Total minutes:" << totalMin << endl
		<< left << setw(21) << "Total due:" << "$" << totalBill << endl
		<< sectionBreak << endl;
}

/*
* CONSOLE OUTPUT # 1 - STANDARD PLAN
* Phone Plan Calculator Program
* By Forrest Moulin
*
* Please enter your account number, followed by
* a space and your service plan type.
* (S for Standard or P for Premium)
*
* ABC123 S
*
* Thank you! Now, please enter the
* total minutes used during the billing cycle.
* Be sure to use an integer.
*
* 120
*
* Forrest's Green Cell Phone Co.
* ------------------------------
* Account number:      ABC123
* Service type:        Standard
* Total minutes:       120
* Total due:           $24.00
* ------------------------------
*/

/*
* CONSOLE OUTPUT # 2 - PREMIUM PLAN
* Phone Plan Calculator Program
* By Forrest Moulin
*
* Please enter your account number, followed by
* a space and your service plan type.
* (S for Standard or P for Premium)
*
* EFG456 P
*
* Thank you! Now, please enter the
* number of daytime and nighttime minutes 
* separated by a space.
* Be sure to enter daytime minutes first.
*
* 100 200
*
* Forrest's Green Cell Phone Co.
* ------------------------------
* Account number:      EFG456
* Service type:        Premium
* Daytime minutes:     100
* Daytime fee:         $2.50
* Nighttime minutes:   200
* Nighttime fee:       $5.00
* Total minutes:       300
* Total due:           $32.50
* ------------------------------
*/
