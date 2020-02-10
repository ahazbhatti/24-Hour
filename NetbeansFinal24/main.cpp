#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <ctime>

  using namespace std;

    // Changes colour of text
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int greentext() { SetConsoleTextAttribute(hConsole, 2); };
    int whitetext() { SetConsoleTextAttribute(hConsole, 15); };
    int redtext() { SetConsoleTextAttribute(hConsole, 4); };
    int bluetext() { SetConsoleTextAttribute(hConsole, 11); };
    int yellowtext() { SetConsoleTextAttribute(hConsole, 14); };
    int darktext() { SetConsoleTextAttribute(hConsole, 8); };

// Global Variables that need to be accessible throughout the different functions

bool MenuLoop = true;
string name("*****");    //Strings have default values so that the form can
string surname("*****"); //be displayed with incomplete fields.
int address1(00);
string address2("*****");
string address3("*****");
string address4("*****");
string postcode("*****");
string telDay("00");
string telEve("00");
int startDate(00);
int startMonth(00);
int startYear(00);
int endDate(00);
int endMonth(00);
int endYear(00);
int membershipNumber(00);
int membershipSelection;
string membershipType("*****");
string memberNotes("*****");

// Global activity variables
string activity("*****");
int activityDate(00);
int activityMonth(00);
int activityYear(00);
double activityPrice(0.00);

//Activity Prices
double Yoga = 30.00;
double sauna = 3.00;
double swimmingPool = 3.50;
double fitnessRoom = 4.50;
double fitnessClassBeginner = 5.50;
double fitnessClassAdvanced = 7.00;
double Tennis = 10.00;
double Basketball = 35.00;

// Resets variables to default values
void resetMemberDetails() {

	name = "*****";
	surname = "*****";
	address1 = 00;
	address2 = "*****";
	address3 = "*****";
	address4 = "*****";
	postcode = "*****";
	startDate = 00;
	startMonth = 00;
	startYear = 00;
	endDate = 00;
	endMonth = 00;
	endYear = 00;
	telDay = "00";
	telEve = "00";
	membershipNumber = 00;
	membershipType = "*****";
	memberNotes = "*****";

	activity = "*****";
	activityDate = 00;
	activityMonth = 00;
	activityYear = 00;
	activityPrice = 00;
};

// Booking form that displays booking variables
void bookingForm() {
	system("clear");
	bluetext();
	cout << "\t\t\t     cmd Booking Details\n";
	whitetext();
	cout << "\t________________________________________________________________\n\n";
	cout << "\tBooking Form   \t";
	cout << "\t  Member: ";
	if (name != "*****") { greentext(); };   // If the field is not the default
	cout << name << " ";                  // value use green text, then
	whitetext();                          // revert back to white text.
	if (surname != "*****") { greentext(); };
	cout << surname << "\n";
	whitetext();
	cout << "\n\t\t         Membership Type: ";
	if (membershipType != "*****") { greentext(); };
	cout << membershipType;
	whitetext();
	cout << "\n\t\t                Activity: ";
	if (activity != "*****") { greentext(); };
	cout << activity;
	whitetext();
	cout << "\n\t\t           Activity Date: ";
	if (activityDate != 00) { greentext(); };
	cout << activityDate << "/" << activityMonth << "/" << activityYear;
	whitetext();
	cout << "\n\t\t          Activity Price: ";
	if (activityPrice != 00.00) { greentext(); };
	cout << activityPrice;
	whitetext();
	cout << "\n\t________________________________________________________________\n\n";
	cout << "\n";
};

// Booking function that saves booking details to a file
void bookingScript() {
	double discount;
	int activityChoice;
	char confirmationSave;

	if (membershipType == "Bronze") {
		discount = 0.9;
	};
	if (membershipType == "Silver") {
		discount = 0.85;
	};
	if (membershipType == "Gold") {
		discount = 0.6;
	};
	if (membershipType == "*****") {
		discount = 1.0;
	};

	bookingForm();
	cout << "Please select an activity:\n\n";
	cout << "1 - Yoga\n";
	cout << "2 - Sauna\n";
	cout << "3 - Swimming Pool\n";
	cout << "4 - Fitness Room\n";
	cout << "5 - Fitness Class (Beginner)\n";
	cout << "6 - Fitness Class (Advanced)\n";
	cout << "7 - Tennis\n";
	cout << "8 - Basketball Gym\n>";
	cin >> activityChoice;

	// Price Calculations for members
	if (activityChoice == 1) { activity = "Yoga"; activityPrice = Yoga * discount; };
	if (activityChoice == 2) { activity = "Sauna"; activityPrice = sauna * discount; };
	if (activityChoice == 3) { activity = "Swimming Pool"; activityPrice = swimmingPool * discount; };
	if (activityChoice == 4) { activity = "Fitness Room"; activityPrice = fitnessRoom * discount; };
	if (activityChoice == 5) { activity = "Fitness Class (Beginner)"; activityPrice = fitnessClassBeginner * discount; };
	if (activityChoice == 6) { activity = "Fitness Class (Advanced)"; activityPrice = fitnessClassAdvanced * discount; };
	if (activityChoice == 7) { activity = "Tennis"; activityPrice = Tennis * discount; };
	if (activityChoice == 8) { activity = "Basketball Gym"; activityPrice = Basketball * discount; };

	// Free activity's for silver and gold members
	if (activityChoice == 3 && membershipType == "Silver") { activityPrice = 0; };
	if (activityChoice == 3 && membershipType == "Gold") { activityPrice = 0; };
	if (activityChoice == 2 && membershipType == "Gold") { activityPrice = 0; };

	bookingForm();

	cout << "\tPlease enter Booking Date(DD): ";
	cin >> activityDate;
	while (cin.fail() || activityDate > 31 || activityDate < 1) {//Catches invalid date
		cin.clear(); cin.ignore();
		cout << "\n\tPlease enter a valid date (1-31): ";
		cin >> activityDate;
	};
	bookingForm();
	cout << "\tPlease enter Booking Month(MM): ";
	cin >> activityMonth;
	while (cin.fail() || activityMonth > 12 || activityMonth < 1) {//Catches invalid month
		cin.clear(); cin.ignore();
		cout << "\n\tPlease enter a valid month (1-12): ";
		cin >> activityMonth;
	}
	bookingForm();
	cout << "\tPlease enter Booking Year(YY): ";
	cin >> activityYear;
	while (cin.fail() || activityYear > 99 || activityYear < 1) {//Catches invalid year
		cin.clear(); cin.ignore();
		cout << "\n\tPlease enter a valid Year (1-99): ";
		cin >> activityYear;
	}
	bookingForm();

	cout << "Is this information correct? <Y/N>";
	cin >> confirmationSave;
	if (confirmationSave == 'y' || confirmationSave == 'Y') {

		string saveBookingName;
		stringstream out;
		out << name << " " << surname << ".booking";
		saveBookingName = out.str();

		ofstream myfile;                                  //Save file structure
		myfile.open(saveBookingName.c_str(), ios::out);
		myfile << name << "\n";
		myfile << surname << "\n";
		myfile << membershipType << "\n";
		myfile << activity << "\n";
		myfile << activityDate << "\n";
		myfile << activityMonth << "\n";
		myfile << activityYear << "\n";
		myfile << activityPrice;
		myfile.close();
		bookingForm();
		greentext();
		cout << "\tBooking have been saved\n\n\t";
		whitetext();
	};
	system("read");
};

// Membership Form that displays membership variables
void MemberForm() {

	system("clear");
	greentext();
	cout << "\t\t\t      Member Details\n";
	whitetext();
	cout << "\t________________________________________________________________\n\n";
	cout << "\tMember Form   \t";
	cout << "\t  Member: ";
	if (name != "*****") { greentext(); };   // If the field is not the default
	cout << name << " ";                  // value use green text, then
	whitetext();                          // revert back to white text.
	if (surname != "*****") { greentext(); };
	cout << surname << "\n";
	whitetext();
	cout << "\t\t\t";
	cout << "\t Address: ";
	if (address1 != 00) { greentext(); };
	cout << address1 << " ";
	whitetext();
	if (address2 != "*****") { greentext(); };
	cout << address2 << "\n";
	whitetext();
	cout << "\t\t";
	cout << "\t\t          ";
	if (address3 != "*****") { greentext(); };
	cout << address3 << "\n";
	whitetext();
	cout << "\t\t\t\t          ";
	if (address4 != "*****") { greentext(); };
	cout << address4 << "\n";
	whitetext();
	cout << "\t\t\t\t          ";
	if (postcode != "*****") { greentext(); };
	cout << postcode << "\n";
	whitetext();
	cout << "\t\t\t   Day Telephone: ";
	if (telDay != "00") { greentext(); };
	cout << telDay;
	whitetext();
	cout << "\n\t\t       Evening Telephone: ";
	if (telEve != "00") { greentext(); };
	cout << telEve << "\n";
	whitetext();
	cout << "\t\t\t      Start date: ";
	if (startDate != 00) { greentext(); };
	cout << startDate << "/";
	whitetext();
	if (startMonth != 00) { greentext(); };
	cout << startMonth << "/";
	whitetext();
	if (startYear != 00) { greentext(); };
	cout << startYear;
	whitetext();
	cout << "\tEnd date: ";
	whitetext();
	if (endDate != 00) { greentext(); };
	cout << endDate << "/";
	whitetext();
	if (endMonth != 00) { greentext(); };
	cout << endMonth << "/";
	whitetext();
	if (endYear != 00) { greentext(); };
	cout << endYear << "\n";
	whitetext();
	cout << "\t________________________________________________________________\n\n";
	cout << "\t\t       Membership number: ";
	if (membershipNumber != 00) { greentext(); };
	cout << membershipNumber;
	whitetext();
	cout << "\n\t\t         Membership Type: ";
	if (membershipType != "*****") { greentext(); };
	cout << membershipType;
	whitetext();
	cout << "\n\n\tNotes: ";
	if (memberNotes != "*****") { greentext(); };
	cout << memberNotes;
	whitetext();
	cout << "\n\t________________________________________________________________\n\n";
	cout << "\n";
};

// Save function for saving member details to a file
void savefile() {
	string saveFileName;
	stringstream out;
	out << name << " " << surname;
	saveFileName = out.str();
	ofstream myfile;                                  //Save file structure
aha	myfile.open(saveFileName.c_str(), ios::out);
	myfile << name << "\n";
	myfile << surname << "\n";
	myfile << address1 << "\n";
	myfile << address2 << "\n";
	myfile << address3 << "\n";
	myfile << address4 << "\n";
	myfile << postcode << "\n";
	myfile << telDay << "\n";
	myfile << telEve << "\n";
	myfile << startDate << "\n";
	myfile << startMonth << "\n";
	myfile << startYear << "\n";
	myfile << endDate << "\n";
	myfile << endMonth << "\n";
	myfile << endYear << "\n";
	myfile << membershipNumber << "\n";
	myfile << membershipType << "\n";
	myfile << memberNotes << "\n";
	myfile.close();
	MemberForm();
	greentext();
	cout << "\tDetails have been saved\n\n\t";
	whitetext();
	system("read");
}

// Main Menu choice 1
void memberDetails() {

	char saveYN;

	MemberForm();
	cout << "\tPlease enter members first name: ";
	cin >> ws;
	getline(cin, name);
	MemberForm();
	cout << "\tPlease enter members last name: ";
	cin >> surname;
	MemberForm();
	cout << "\tPlease enter members street number: ";
	cin >> address1;
	while (cin.fail() || address1 < 1)  // Checks for invalid entry.
	{
		cin.clear(); cin.ignore();
		cout << "\n\tPlease enter a valid street number: "; cin >> address1;
	}
	MemberForm();
	cout << "\tPlease enter members street name: ";
	cin >> ws;                        // Allows the user to enter more than one word
	getline(cin, address2);          // in a string by allowing white spaces.
	MemberForm();
	cout << "\tPlease enter Apt/House number: ";
	getline(cin, address3);
	MemberForm();
	cout << "\tPlease enter member city: ";
	getline(cin, address4);
	MemberForm();
	cout << "\tPlease enter member postcode: ";
	cin >> ws;
	getline(cin, postcode);
	MemberForm();
	cout << "\tPlease enter Daytime Telephone Number: ";
	//cin >> ws;
	getline(cin, telDay);
	while (cin.fail()) { //Handles character in integer variable
		cin.clear();
		cin.ignore();
		cout << "\tPlease enter Daytime Telephone Number: ";
		cin >> telDay;
	};
	MemberForm();
	cout << "\tPlease enter Evening Telephone Number: ";
	//cin >> ws;
	getline(cin, telEve);
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "\tPlease enter Evening Telephone Number: ";
		cin >> telEve;
	};
	MemberForm();
	cout << "\tPlease enter Membership Start Date(DD): ";
	cin >> startDate;
	while (cin.fail() || startDate > 31 || startDate < 1) {//Catches invalid date
		cin.clear(); cin.ignore();
		cout << "\n\tPlease enter a valid date (1-31): ";
		cin >> startDate;
	};
	MemberForm();
	cout << "\tPlease enter Membership Start Month(MM): ";
	cin >> startMonth;
	while (cin.fail() || startMonth > 12 || startMonth < 1) {//Catches invalid month
		cin.clear(); cin.ignore();
		cout << "\n\tPlease enter a valid month (1-12): ";
		cin >> startMonth;
	}
	MemberForm();
	cout << "\tPlease enter Membership Start Year(YY): ";
	cin >> startYear;
	while (cin.fail() || startYear > 99 || startYear < 1) {//Catches invalid year
		cin.clear(); cin.ignore();
		cout << "\n\tPlease enter a valid Year (1-99): ";
		cin >> startYear;
	}
	MemberForm();
	cout << "\tPlease enter Membership End Date(DD): ";
	cin >> endDate;
	while (cin.fail() || endDate > 31 || endDate < 1) {
		cin.clear(); cin.ignore();
		cout << "\n\tPlease enter a valid date (1-31): ";
		cin >> endDate;
	}
	MemberForm();
	cout << "\tPlease enter Membership End Month(MM): ";
	cin >> endMonth;
	while (cin.fail() || endMonth > 12 || endMonth < 1) {
		cin.clear(); cin.ignore();
		cout << "\n\tPlease enter a valid month (1-12): ";
		cin >> endMonth;
	}
	MemberForm();
	cout << "\tPlease enter Membership End Year(YY): ";
	cin >> endYear;
	while (cin.fail() || endYear > 99 || endYear < 1) {
		cin.clear(); cin.ignore();
		cout << "\n\tPlease enter a valid year (1-99): ";
		cin >> endYear;
	}
	MemberForm();
	cout << "\tEnter 6 Digit membership card number: ";
	cin >> membershipNumber;
	while (cin.fail() || membershipNumber < 100000 || membershipNumber > 999999) {
		cin.clear(); cin.ignore();      //Ensures membership numbers are 6 digits
		cout << "\n\tPlease enter a valid membership card number (6 Digits): ";
		cin >> membershipNumber;
	};
	MemberForm();
	cout << "\tPlease enter membership type:\n\t1 - Bronze\n\t2 - Silver\n\t3 - Gold\n\t> : ";
	cin >> membershipSelection;
	while (cin.fail() || membershipSelection < 1 || membershipSelection >3) {

		cin.clear();
		cin.ignore();           //Handles invalid membership selection


		cout << "\n\tPlease enter a valid membership type.\n\t1 - Bronze - 10.00 Per month\n\t2 - Silver - 15.00 Per month\n\t3 - Gold  - 20.00 Per month\n\t> : ";
		cin >> membershipSelection;
	};
	switch (membershipSelection) {
	case 1:
		membershipType = "Bronze";
		break;
	case 2:
		membershipType = "Silver";
		break;
	case 3:
		membershipType = "Gold";
		break;
		//default :

	};
	MemberForm();
	cout << "\tPlease enter any additional notes:\n\t";
	cin.ignore();
	getline(cin, memberNotes);
	MemberForm();
	cout << "\tSave these details to a file? <Y/N> ";

	//Confirmation before saving a file
	cin >> saveYN;
	if (saveYN == 'y' || saveYN == 'Y') {
		savefile();
	};
};

// Main Menu choice 2
void createBooking() {

	char confirm;
	system("clear");
	char filebooking[100];
	ifstream file_ptr;
	cout << "\n\t\t\t\tSelect a member\n\n";
	system("dir/b *.");
	cout << "\tPlease type the name of the member you\n";
	cout << "\twish to create a booking for as it appears above OR\n";
	cout << "\ttype z (Lower case) to return to main menu: ";
	cin.ignore();
	gets(filebooking);
	if (filebooking[0] != 'z') {

		file_ptr.open(filebooking, ios::in);
		// char in_char;
		while (!file_ptr)
		{
			cout << "Member does not exist\n";
			gets(filebooking);
			file_ptr.open(filebooking, ios::in);
		}
		getline(file_ptr, name);
		getline(file_ptr, surname);
		file_ptr >> address1;
		getline(file_ptr, address2); // Duplicate required to eliminate
		getline(file_ptr, address2); // empty field bug when using string after integer.
		getline(file_ptr, address3);
		getline(file_ptr, address4);
		getline(file_ptr, postcode);
		getline(file_ptr, telDay);
		getline(file_ptr, telEve);
		//file_ptr >> telDay;
		//file_ptr >> telEve;
		file_ptr >> startDate >>
			startMonth >>
			startYear >>
			endDate >>
			endMonth >>
			endYear >>
			membershipNumber;
		getline(file_ptr, membershipType); // Duplicate required to eliminate
		getline(file_ptr, membershipType); // empty field bug when using string after integer.
		getline(file_ptr, memberNotes);

		MemberForm();

		greentext();
		whitetext();

		file_ptr.close();

		cout << "\n\tCreate booking for this member? <Y/N>";
		cin >> confirm;
		if (confirm == 'y' || confirm == 'Y') {

			bookingScript();
		};
	};
};

// Main Menu choice 3
void openFile() {


	// Allows user to select the option of opening a booking file or a member file
	system("clear");
	int fileMenuChoice;
	cout << "\t\tOpen a Account\n\n";
	cout << "1 - Open a Member Account\n\n";
	cout << "2 - Open a Booking Account\n\n";
	cout << "Please select a file type to open:";
	cin >> fileMenuChoice;

	// Menu Option to open Member File
	if (fileMenuChoice == 1)
	{
		cout << "Open Member File";
		system("clear");
		char filename[100];
		ifstream file_ptr;
		cout << "\n\t\t\t\tSaved Members:\n\n";
		system("dir/b *.");
		cout << "\n\nPlease type the name of the member you\n";
		cout << "     wish to open as it appears above OR\n";
		cout << "     type z (Lower case) to return to main menu: ";
		cin.ignore();
		gets(filename);
		if (filename[0] != 'z') {

			file_ptr.open(filename, ios::in);
			
			while (!file_ptr)
			{
				cout << "Member does not exist\n";
				gets(filename);
				file_ptr.open(filename, ios::in);
			}
			getline(file_ptr, name);
			getline(file_ptr, surname);
			file_ptr >> address1;
			getline(file_ptr, address2); // Duplicate required to eliminate
			getline(file_ptr, address2); // empty field bug when using string after integer.
			getline(file_ptr, address3);
			getline(file_ptr, address4);
			getline(file_ptr, postcode);
			getline(file_ptr, telDay);
			getline(file_ptr, telEve);
			//file_ptr >> telDay;
			//file_ptr >> telEve;
			file_ptr >> startDate >>
				startMonth >>
				startYear >>
				endDate >>
				endMonth >>
				endYear >>
				membershipNumber;
			getline(file_ptr, membershipType); // Duplicate required to eliminate
			getline(file_ptr, membershipType); // empty field bug when using string after integer.
			getline(file_ptr, memberNotes);
			MemberForm();
			greentext();
			whitetext();
			file_ptr.close();
			system("read");
		};
	};

	// Menu Option to open Booking File

	if (fileMenuChoice == 2) {
		{
			cout << "Open Booking File";
			system("clear");
			char filename[100];
			ifstream file_ptr;
			cout << "\n\t\t\t\tSaved Bookings:\n\n";
			system("dir/b *.booking");
			cout << "\nPlease type the name of the booking you\n";
			cout << "    wish to open as it appears above OR\n";
			cout << "    type z (Lower case) to return to main menu: ";
			cin.ignore();
			gets(filename);
			if (filename[0] != 'z') {

				file_ptr.open(filename, ios::in);
				// char in_char;
				while (!file_ptr)
				{
					cout << "Member does not exist\n";
					gets(filename);
					file_ptr.open(filename, ios::in);
				}
				getline(file_ptr, name);
				getline(file_ptr, surname);

				getline(file_ptr, membershipType); // Duplicate required to eliminate
												   //getline(file_ptr, membershipType); // empty field bug when using string after integer.
				getline(file_ptr, activity);
				file_ptr >> activityDate;
				file_ptr >> activityMonth;
				file_ptr >> activityYear;
				file_ptr >> activityPrice;

				//getline(file_ptr, activityDate);
				//getline(file_ptr, activityMonth);
				//getline(file_ptr, activityYear);


				bookingForm();
				greentext();
				whitetext();

				file_ptr.close();
				system("read");
			};
		};
	};
};

// Main Menu choice 4
void priceList() {
	system("clear");
	cout << "\t\tPrice List\n\n";

	cout << "\t\t\t\tActivities\n\t";
	cout << "\t\t\tNone member  |  Bronze  |  Silver  |  Gold";
	cout << "\n\n\tYoga                    $" << Yoga << "\t        " << Yoga * 0.9 << "\t   " << Yoga * 0.85 << "   \t" << Yoga * 0.6;
	cout << "\n\n\tSauna                   $" << sauna << "\t        " << sauna * 0.9 << "\t   " << sauna * 0.85 << "\t        " << sauna * 0.6;
	cout << "\n\n\tSwimming Pool           $" << swimmingPool << "\t        " << swimmingPool * 0.9 << "\t   " << swimmingPool * 0.85 << "\t" << swimmingPool * 0.6;
	cout << "\n\n\tFitness Room            $" << fitnessRoom << "\t        " << fitnessRoom * 0.9 << "\t   " << fitnessRoom * 0.85 << "\t" << fitnessRoom * 0.6;
	cout << "\n\n\tFitness Class";
	cout << "\n\t  Beginner              $" << fitnessClassBeginner << "\t        " << fitnessClassBeginner * 0.9 << "\t   " << fitnessClassBeginner * 0.85 << "\t" << fitnessClassBeginner * 0.6;
	cout << "\n\t  Advanced              $" << fitnessClassAdvanced << "\t        " << fitnessClassAdvanced * 0.9 << "\t   " << fitnessClassAdvanced * 0.85 << "\t        " << fitnessClassAdvanced * 0.6;
	cout << "\n\n\tTennis                  $" << Tennis << "\t        " << Tennis * 0.9 << "\t   " << Tennis * 0.85 << "\t        " << Tennis * 0.6;
	cout << "\n\n\tBasketball Gym          $" << Basketball << "\t        " << Basketball * 0.9 << "\t   " << Basketball * 0.85 << "\t" << Basketball * 0.6;
	cout << "\n\n\n\t";

	system("read");
};

// Main Menu choice 5
void help() {
	system("clear");
	cout << "\t\t\t\tHelp\n\n";

	cout << "To enter a new member into the system, Choose option 1 from the Main Menu.\n";
	cout << "Enter the new members details into the membership form and press Y to save once finished.\n\n\n";

	cout << "To create a booking, select option 2 from the main menu.\n";
	cout << "Enter the members name from the list OR enter 'None Member' if the member is  not a member\n";
	cout << "Enter the booking choices and then press Y to save the booking\n\n\n";

	cout << "To open a member or booking file, choose option 3 at the main menu.\n";
	cout << "Select option 1 to open a member file or option 2 to open a booking file\n";
	cout << "Type the name of a file as it is displayed on the list to open and view it.\n\n\n";

	cout << "To view a price list, select option 4 from the main menu.\n\n\n";

	system("read");
};

// Main Menu choice 6
void exit() {
	MenuLoop = false;
	//system ("clear");
	//exit (0);

};

// Main Menu function
void mainMenu() {

	// Private variable used for menu selection
	int menuchoice;

	system("clear");

	resetMemberDetails();

        cout << "\t\t_________________________________________\n";
	cout << "\n\t\tWelcome to 24 Hour Fitness Management System\n";
        cout << "\t\t_________________________________________ \n\n\n";
	cout << "\t\t\t\tMain Menu\n\n\n";
        cout << "\t\t1 - Add a member to system\n\n";
	cout << "\t\t2 - Membership booking\n\n";
	cout << "\t\t3 - Open a account\n\n";
	cout << "\t\t4 - View price list\n\n";
	cout << "\t\t5 - Assist-NewEmployees\n\n";
	cout << "\t\t6 - Exit\n\n\n";
	cout << "\t\t\tPlease choose an option: ";
	cin >> menuchoice;

	//Prevents a character entry from crashing the program
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "\n\t\tPlease enter a valid number:"; cin >> menuchoice;
	};

	// Switch statement for menu selection
	switch (menuchoice) {

		// Enter new member function
	case 1:
		memberDetails();
		break;
	case 2:
		createBooking();
		break;

	case 3:
		openFile();
		break;

	case 4:
		priceList();
		break;

	case 5:
		help();
		break;

	case 6:
		exit();
		break;

	default:
		cout << "\n\tPlease enter a correct menu choice\n\n\t";
		system("read");
	};
};

// Password function
void password() {

	string pass;
	int passCount = 0;

	cout << "\n\n\n\t\t\t\t------------------------------------\n";
	cout << "\t\t\t\tEmployees Only\n";
	cout << "\t\t\t\t------------------------------------\n";
	cout << "\n\n\n\t\t\t\t------------------------------------\n";
	cout << "\t\t\t\t**Enter Password for Verification**\n";
	cout << "\t\t\t\t------------------------------------\n";
        cout << "\n\n\n\t\t\t\tProtected Access II (WPA)(WPA2)\n";
        cout << "\n\n\t\t\t\t->";
	cin >> pass;                   //Promps user for password

	while (pass != "ahaz")
	{
		passCount++;
		redtext();
		cout << "\t\t\t\tPassword Incorrect!\n";
		if (passCount >= 3)                         //Three failed attemps exits program
		{
			redtext();
			cout << "\n\t\t\t\tLOGIN FAILED!";
			whitetext();
			exit(0);
		};

		whitetext();
		cout << "\t\t\t\tTry Again:\n\t\t\t\t->";
		cin >> pass;

	};
	greentext();
	cout << "\n\t\t\t\tPassword Accepted!\n\t\t\t\tPress any key to continue...";
	whitetext();
	cin.ignore();
	cin.get();
};

// Main function
int main()
{

	password();                                 //Password Screen
	while (MenuLoop == true) { mainMenu(); };      //Main menu loop

	return 0;
}