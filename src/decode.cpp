#include <iostream>
#include <iomanip>

using namespace std;

void decode_bcdUSB(uint16_t bcdUSB) {
	if(bcdUSB == 0x0200) cout << "USB 2.0 ";
	else if(bcdUSB == 0x0110) cout << "USB 1.1 ";
	else if(bcdUSB == 0x0101) cout << "USB 1.01 ";
	else cout << "USB " << hex << static_cast<int>(bcdUSB) << ' ';
}

void decode_DeviceClass(uint8_t DeviceClass) {
	switch(DeviceClass) {
		case LIBUSB_CLASS_PER_INTERFACE:
			cout << "(Defined at Interface level)" << endl;	// Each Interface Specifies Own Class
		break;
		case LIBUSB_CLASS_AUDIO:
			cout << "Audio" << endl;
		break;
		case LIBUSB_CLASS_COMM:
			cout << "Communications" << endl;
		break;
		case LIBUSB_CLASS_HID:
			cout << "Human Interface Device" << endl;
		break;
		case LIBUSB_CLASS_PHYSICAL:
			cout << "Physical" << endl;
		break;
		case LIBUSB_CLASS_PRINTER:
			cout << "Printer" << endl;
		break;
		case LIBUSB_CLASS_PTP:
			cout << "Image" << endl;
		break;
		case LIBUSB_CLASS_MASS_STORAGE:
			cout << "Mass storage" << endl;
		break;
		case LIBUSB_CLASS_HUB:
			cout << "Hub" << endl;
		break;
		case LIBUSB_CLASS_DATA:
			cout << "Data" << endl;
		break;
		case LIBUSB_CLASS_SMART_CARD:
			cout << "Smart Card" << endl;
		break;
		case LIBUSB_CLASS_CONTENT_SECURITY:
			cout << "Content Security" << endl;
		break;
		case LIBUSB_CLASS_VIDEO:
			cout << "Video" << endl;
		break;
		case LIBUSB_CLASS_PERSONAL_HEALTHCARE:
			cout << "Personal Healthcare" << endl;
		break;
		case LIBUSB_CLASS_DIAGNOSTIC_DEVICE:
			cout << "Diagnostic Device" << endl;
		break;
		case LIBUSB_CLASS_WIRELESS:
			cout << "Wireless" << endl;
		break;
		case LIBUSB_CLASS_APPLICATION:
			cout << "Application" << endl;
		break;
		case LIBUSB_CLASS_VENDOR_SPEC:
			cout << "Vendor-Specific" << endl;
		break;
		default:
			cout << endl;
	}
}

void decode_DescriptorType(uint8_t libusb_descriptor_type) {
	switch(libusb_descriptor_type) {
		case LIBUSB_DT_DEVICE:
			cout << "Device Descriptor" << endl;
		break;
		case LIBUSB_DT_CONFIG:
			cout << "Configuration Descriptor" << endl;
		break;
		case LIBUSB_DT_STRING:
			cout << "String Descriptor" << endl;
		break;
		case LIBUSB_DT_INTERFACE:
			cout << "Interface Descriptor" << endl;
		break;
		case LIBUSB_DT_ENDPOINT:
			cout << "Endpoint Descriptor" << endl;
		break;
		case LIBUSB_DT_BOS:
			cout << "BOS Descriptor" << endl;
		break;
		case LIBUSB_DT_DEVICE_CAPABILITY:
			cout << "Device Capability Descriptor" << endl;
		break;
		case LIBUSB_DT_HID:
			cout << "Human Interface Device Descriptor" << endl;
		break;
		case LIBUSB_DT_REPORT:
			cout << "Human Interface Device Report Descriptor" << endl;
		break;
		case LIBUSB_DT_PHYSICAL:
			cout << "Physical Descriptor" << endl;
		break;
		case LIBUSB_DT_HUB:
			cout << "Hub Descriptor" << endl;
		break;
		case LIBUSB_DT_SUPERSPEED_HUB:
			cout << "SuperSpeed Hub Descriptor" << endl;
		break;
		case LIBUSB_DT_SS_ENDPOINT_COMPANION:
			cout << "SuperSpeed Endpoint Companion Descriptor" << endl;
		break;
		default:
			cout << endl;
	}
}
