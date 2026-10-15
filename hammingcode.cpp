#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {

    int binary[4];

    cout << "Enter 4 bits binary code:" << endl;

    for (int i = 0; i < 4; i++) {
        cout << "Enter bit " << (i + 1) << " : ";
        int bit;
        cin >> bit;

        if (bit != 0 && bit != 1) {
            cout << "Invalid input: Code must only contain 0 and 1" << endl;
            return 0;
        }

        binary[i] = bit;
    }

    cout << "Your binary code is: ";

    for (int bit : binary) {
        cout << bit;
    }

    cout << endl;

    int m = 4;
    int r = 0;

    while (true) {
        if (pow(2, r) >= m + r + 1) {
            break;
        }
        r++;
    }

    cout << "Number of parity bits r: " << r << endl;

    int totalBits = m + r;
    int finalBinary[totalBits] = {};

    int k = 0;

    for (int i = 0; i < totalBits; i++) {
        if (k >= r) {
            break;
        }

        int position = pow(2, k);

        finalBinary[totalBits - position] = 0;
        k++;
    }

    int binaryIndex = 0;

    for (int i = totalBits; i >= 1; i--) {

        int arrayIndex = totalBits - i;

        if (i != 1 && i != 2 && i != 4) {
            finalBinary[arrayIndex] = binary[binaryIndex];
            binaryIndex++;
        }
    }

    cout << "Your binary code is with parity bits set to 0: ";

    for (int bit : finalBinary) {
        cout << bit;
    }

    cout << endl;

    // Calculate parity bits
    for (int parityIndex = 0; parityIndex < r; parityIndex++) {

        int parityPosition = pow(2, parityIndex);
        int parity = 0;

        for (int position = 1; position <= totalBits; position++) {

            if ((position & parityPosition) != 0) {

                int arrayIndex = totalBits - position;

                parity = parity ^ finalBinary[arrayIndex];
            }
        }

        finalBinary[totalBits - parityPosition] = parity;
    }

    cout << "Final signal: ";

    for (int bit : finalBinary) {
        cout << bit;
    }

    cout << endl << endl;

    // Receiver
    cout << "Enter received codeword: ";

    string received;
    cin >> received;

    if (received.length() != totalBits) {
        cout << "Invalid codeword! Enter exactly "
             << totalBits << " bits." << endl;
        return 0;
    }

    int receivedBinary[totalBits];

    for (int i = 0; i < totalBits; i++) {

        char bit = received[i];

        if (bit != '0' && bit != '1') {
            cout << "Invalid input: Code must only contain 0 and 1"
                 << endl;
            return 0;
        }

        receivedBinary[i] = bit - '0';
    }

    int errorPosition = 0;

    // Check parity bits
    for (int parityIndex = 0; parityIndex < r; parityIndex++) {

        int parityPosition = pow(2, parityIndex);
        int parity = 0;

        for (int position = 1; position <= totalBits; position++) {

            if ((position & parityPosition) != 0) {

                int arrayIndex = totalBits - position;

                parity = parity ^ receivedBinary[arrayIndex];
            }
        }

        if (parity != 0) {
            errorPosition += parityPosition;
        }
    }

    cout << endl;
    cout << "----- RECEIVER -----" << endl;

    if (errorPosition == 0) {

        cout << "No error detected." << endl;

    } else {

        cout << "Error detected at bit position: "
             << errorPosition
             << " from the right" << endl;

        int errorArrayIndex = totalBits - errorPosition;

        // Correct the error
        receivedBinary[errorArrayIndex] =
            receivedBinary[errorArrayIndex] ^ 1;

        cout << "Corrected Codeword: ";

        for (int bit : receivedBinary) {
            cout << bit;
        }

        cout << endl;
    }

    // Recover original data bits
    cout << "Recovered Data Bits: ";

    for (int position = totalBits; position >= 1; position--) {

        if (position != 1 &&
            position != 2 &&
            position != 4) {

            int arrayIndex = totalBits - position;

            cout << receivedBinary[arrayIndex];
        }
    }

    cout << endl;

    return 0;
}
