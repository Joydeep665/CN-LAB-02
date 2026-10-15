#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int o1, o2, o3, o4;
    char dot;
    int cidr;

    cout << "Enter base IP address: ";
    cin >> o1 >> dot >> o2 >> dot >> o3 >> dot >> o4;

    cout << "Enter CIDR prefix: ";
    cin >> cidr;

    if (cidr < 24 || cidr > 30) {
        cout << "Invalid CIDR. Enter value between 24 and 30.";
        return 0;
    }

    int hostBits = 32 - cidr;
    int blockSize = pow(2, hostBits);
    int numSubnets = 256 / blockSize;
    int usableHosts = blockSize - 2;
    int subnetMask = 256 - blockSize;

    cout << "\nSubnet Mask: 255.255.255." << subnetMask << endl;
    cout << "Number of Subnets: " << numSubnets << endl;
    cout << "Usable Hosts per Subnet: " << usableHosts << endl;

    for (int i = 0; i < numSubnets; i++) {

        int network = i * blockSize;
        int firstHost = network + 1;
        int lastHost = network + blockSize - 2;
        int broadcast = network + blockSize - 1;

        cout << "\n-----------------------------" << endl;
        cout << "Subnet " << i + 1 << endl;

        cout << "Network Address: "
             << o1 << "." << o2 << "." << o3 << "." << network << endl;

        cout << "First Host: "
             << o1 << "." << o2 << "." << o3 << "." << firstHost << endl;

        cout << "Last Host: "
             << o1 << "." << o2 << "." << o3 << "." << lastHost << endl;

        cout << "Broadcast Address: "
             << o1 << "." << o2 << "." << o3 << "." << broadcast << endl;
    }

    return 0;
}
