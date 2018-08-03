#include <iostream>
#include <cstdlib>
#include <libusb-1.0/libusb.h>

using namespace std;

//#include "getter.cpp"
#include "decode.cpp"

int browseDeviceData(struct libusb_device *device){
	system("clear");	// Clear Screen

	string prompt = "";

	struct libusb_device_descriptor desc;
	int return_val = libusb_get_device_descriptor(device, &desc);
	if(return_val < 0){
		cout << "Error getting device descriptor" << endl;
		exit(1);
	}

	//cout << printDevice(device) << endl;	// 'get descriptor' code in here too
	cout << "Descriptor Length = " << desc.bLength << endl
		<< "Descriptor Type = ";
	decode_DescriptorType(desc.bDescriptorType);
	decode_bcdUSB(desc.bcdUSB);
	cout << ' ';
	decode_DeviceClass(desc.bDeviceSubClass);
	cout << "Device Subclass = " << static_cast<int>(desc.bDeviceSubClass)
		<< "Device Protocol = " << desc.bDeviceProtocol << endl
		<< "Maximum Packet Size for Endpoint 0 = " << static_cast<int>(desc.bMaxPacketSize0) << endl
		<< "Vendor ID = " << desc.idVendor << endl
		<< "Product ID = " << desc.idProduct << endl
		<< "Release # = " << desc.bcdDevice << endl;
	//get (desc.iManufacturer);
	//get (desc.iProduct);
	cout << "Serial Number = " << desc.iSerialNumber << endl
		<< "Number of possible configurations = "  << static_cast<int>(desc.bNumConfigurations) << endl
		<< endl
		<< "b: Back to Device List\n"
		<< "q: Quit USB Manager\n" << endl;

	// Read User Input
	string user_input;
	getline(cin, user_input);

	if(user_input.compare("b") == 0) return 0;
	else if(user_input.compare("q") == 0) exit(0);
	else prompt = "\tPlease choose one of the options provided below.\n";
}

int browseDevices(){
	int return_value;

	// Initialize Session
	return_value = libusb_init(NULL);
	if(return_value != LIBUSB_SUCCESS) {
		cout << "Error Initializing LibUSB" << endl;
		libusb_exit(NULL);
		exit(1);
	}

	// Get Device List
	struct libusb_device **device_list;	// pointer array
	ssize_t num_devices = libusb_get_device_list(NULL, &device_list);
	if(num_devices < 0){
		cout << "No devices found" << endl;
		libusb_free_device_list(device_list, 1);
		libusb_exit(NULL);
		exit(1);
	}

	// Print Menu
	string prompt = "There are " + to_string(num_devices) + " devices.\n";
	while(true) {
		system("clear");	// Clear Screen

		// Print Device List
		cout << prompt << endl;
		for(int i = 0; i < num_devices; i++){
			cout << i << ": ";	// Print Index

			// Get Device Descriptor
			struct libusb_device_descriptor desc;
			return_value = libusb_get_device_descriptor(device_list[i], &desc);
			if (return_value != LIBUSB_SUCCESS) {
				cout << libusb_error_name(return_value) << endl;
				cout << "Error: Failed to Get Device Descriptor" << endl;
				exit(1);
			}

			// Open Device
			struct libusb_device_handle *handle = NULL;
			return_value = libusb_open(device_list[i], &handle);
			if(return_value != LIBUSB_SUCCESS) {
				libusb_free_device_list(device_list, 1);
				libusb_exit(NULL);
				exit(1);
			}

			// Print Device Name
			unsigned char data[256];
			if (desc.iProduct) {
				return_value = libusb_get_string_descriptor_ascii(handle, desc.iProduct, data, sizeof(data));
				if (return_value > 0) cout << data << ", ";
			}

			// Close Device
			libusb_close(handle);

			// Print USB Version
			decode_bcdUSB(desc.bcdUSB);

			// Print Device Type
			decode_DeviceClass(desc.bDeviceClass);
		}
		cout << endl
			//<< "s: Save as\n"
			//<< "r: Record Step\n"
			<< "b: Back to Main Menu\n"
			<< "q: Quit USB Manager\n" << endl;

		// Read User Input
		string user_input;
		getline(cin, user_input);

		// Process Input
		if(user_input.length() == 1 && isdigit(user_input[0])) browseDeviceData(device_list[stoi(user_input, nullptr, 0)]);;
		if(user_input.compare("b") == 0) return 0;
		else if(user_input.compare("q") == 0) exit(0);
		else prompt = "\tPlease choose one of the options provided below.\n";
	}

	// Free Device List & End Session
	libusb_free_device_list(device_list, 1);
	libusb_exit(NULL);
	return 0;
}
