#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    cout << "Subnetting is the process of dividing a larger IP network into smaller, manageable sub-networks called subnets to improve efficiency, security, and address management." << endl;
    
    string ip;
    cout << "Enter IP address: ";
    cin >> ip;

    string first_octet_str = "";
    for (char c : ip) {
        if (c == '.') {
            break;
        }
        first_octet_str += c;
    }

    int first_octet = stoi(first_octet_str);

    if (first_octet >= 0 && first_octet <= 126) {
        cout << "Class A" << endl;
        cout << "Subnet Mask: 255.0.0.0" << endl;
        cout << "Class Range: 0.0.0.0 to 127.255.255.255" << endl;
        cout << "Number of Networks: 2^7 = 128" << endl;
        cout << "Reason for Networks: Class A uses 1 bit for the network prefix (fixed as 0), leaving 7 bits for the network ID, resulting in 2^7 networks." << endl;
        cout << "Hosts per Network: 2^24 - 2 = 16,777,214" << endl;
        cout << "Reason for -2: One IP address is reserved for the Network ID and another IP address is reserved for the Broadcast address." << endl;
    }
    else if (first_octet >= 128 && first_octet <= 191) {
        cout << "Class B" << endl;
        cout << "Subnet Mask: 255.255.0.0" << endl;
        cout << "Class Range: 128.0.0.0 to 191.255.255.255" << endl;
        cout << "Number of Networks: 2^14 = 16,384" << endl;
        cout << "Reason for Networks: Class B uses 2 bits for the network prefix (fixed as 10), leaving 14 bits for the network ID, resulting in 2^14 networks." << endl;
        cout << "Hosts per Network: 2^16 - 2 = 65,534" << endl;
        cout << "Reason for -2: One IP address is reserved for the Network ID and another IP address is reserved for the Broadcast address." << endl;
    }
    else if (first_octet >= 192 && first_octet <= 223) {
        cout << "Class C" << endl;
        cout << "Subnet Mask: 255.255.255.0" << endl;
        cout << "Class Range: 192.0.0.0 to 223.255.255.255" << endl;
        cout << "Number of Networks: 2^21 = 2,097,152" << endl;
        cout << "Reason for Networks: Class C uses 3 bits for the network prefix (fixed as 110), leaving 21 bits for the network ID, resulting in 2^21 networks." << endl;
        cout << "Hosts per Network: 2^8 - 2 = 254" << endl;
        cout << "Reason for -2: One IP address is reserved for the Network ID and another IP address is reserved for the Broadcast address." << endl;
    }
    else if (first_octet == 127) {
        cout << "Reserved Loopback" << endl;
        cout << "Subnet Mask: 255.0.0.0" << endl;
        cout << "Class Range: 127.0.0.0 to 127.255.255.255" << endl;
        cout << "Number of Networks: Not Applicable" << endl;
        cout << "Reason for Networks: Used exclusively for host self-diagnosis and internal loopback traffic." << endl;
        cout << "Hosts per Network: Not Applicable" << endl;
        cout << "Reason for -2: Used exclusively for host self-diagnosis and internal loopback traffic." << endl;
    }
    else if (first_octet >= 224 && first_octet <= 239) {
        cout << "Class D" << endl;
        cout << "Subnet Mask: Not Applicable (Multicast)" << endl;
        cout << "Class Range: 224.0.0.0 to 239.255.255.255" << endl;
        cout << "Number of Networks: Not Applicable" << endl;
        cout << "Reason for Networks: Reserved for multicasting and does not use traditional network/host ID partitioning." << endl;
        cout << "Hosts per Network: Not Applicable" << endl;
        cout << "Reason for -2: Reserved for multicasting and does not use traditional network/host ID partitioning." << endl;
    }
    else if (first_octet >= 240 && first_octet <= 255) {
        cout << "Class E" << endl;
        cout << "Subnet Mask: Not Applicable (Experimental)" << endl;
        cout << "Class Range: 240.0.0.0 to 255.255.255.255" << endl;
        cout << "Number of Networks: Not Applicable" << endl;
        cout << "Reason for Networks: Reserved for experimental and research purposes." << endl;
        cout << "Hosts per Network: Not Applicable" << endl;
        cout << "Reason for -2: Reserved for experimental and research purposes." << endl;
    }
    else {
        cout << "Invalid IP address" << endl;
    }

    return 0;
}
