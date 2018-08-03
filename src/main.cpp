#include <iostream>
#include <cstdlib>

using namespace std;

#include "browse.cpp"

int main() {
	system("clear");	// Clear Screen

	cout << "\tHello,\n\twelcome to the USB Manager.\n" << endl;

	string prompt = "\tChoose a menu option to begin.\n";
	while(true) {
		cout << prompt << endl;	// Prompt User for input

		// Print Menu
		cout << "d: Browse Devices\n"
			//<< "r: Record Session\n"
			//<< "v: View Saved Devices\n"
			<< "q: Quit USB Manager\n" << endl;

		// Read User Input
		string menu_option;
		getline(cin, menu_option);

		// Process Input
		if(menu_option.compare("d") == 0) browseDevices();
		else if(menu_option.compare("q") == 0) exit(0);
		else prompt = "\tPlease choose one of the options provided below.\n";

		system("clear");	// Clear Screen
	}
	return 0;
}
