#include <bits/stdc++.h>
using namespace std;

int main() {
    string data;

    // 1. Read 4-bit data
    cout << "Enter 4-bit data: ";
    cin >> data;

    if (data.length() != 4 ||
        data.find_first_not_of("01") != string::npos) {
        cout << "Invalid input! Enter exactly 4 binary bits." << endl;
        return 0;
    }

    // Hamming (7,4) positions:
    // Position: 1 2 3 4 5 6 7
    //           P P D P D D D

    vector<int> h(8, 0); // Use positions 1-7

    // 2. Place data bits
    h[3] = data[0] - '0';
    h[5] = data[1] - '0';
    h[6] = data[2] - '0';
    h[7] = data[3] - '0';

    // 3. Calculate parity bits (Even Parity)

    // P1 checks positions 1, 3, 5, 7
    h[1] = h[3] ^ h[5] ^ h[7];

    // P2 checks positions 2, 3, 6, 7
    h[2] = h[3] ^ h[6] ^ h[7];

    // P4 checks positions 4, 5, 6, 7
    h[4] = h[5] ^ h[6] ^ h[7];

    // 4. Display encoded Hamming code
    cout << "\nEncoded Hamming Code: ";
    for (int i = 1; i <= 7; i++) {
        cout << h[i];
    }
    cout << endl;

    // -------------------------------------------------------
    // 5. Simulate an error
    // -------------------------------------------------------

    int error_bit;
    cout << "\nEnter error position (1-7, or 0 for no error): ";
    cin >> error_bit;

    vector<int> received = h;

    if (error_bit >= 1 && error_bit <= 7) {
        received[error_bit] ^= 1;
    }

    // 6. Display received code
    cout << "Received Hamming Code: ";
    for (int i = 1; i <= 7; i++) {
        cout << received[i];
    }
    cout << endl;

    // -------------------------------------------------------
    // 7. Calculate syndrome
    // -------------------------------------------------------

    int c1 = received[1] ^ received[3] ^
             received[5] ^ received[7];

    int c2 = received[2] ^ received[3] ^
             received[6] ^ received[7];

    int c4 = received[4] ^ received[5] ^
             received[6] ^ received[7];

    int error_position = c1 + (c2 * 2) + (c4 * 4);

    // 8. Detect and correct error
    if (error_position == 0) {
        cout << "\nResult: No error detected." << endl;
    } 
    else {
        cout << "\nResult: Error detected at position "
             << error_position << "!" << endl;

        // Correct the error
        received[error_position] ^= 1;

        cout << "Corrected Hamming Code: ";
        for (int i = 1; i <= 7; i++) {
            cout << received[i];
        }
        cout << endl;
    }

    // 9. Extract original data
    cout << "Recovered Data: ";
    cout << received[3]
         << received[5]
         << received[6]
         << received[7] << endl;

    return 0;
}
