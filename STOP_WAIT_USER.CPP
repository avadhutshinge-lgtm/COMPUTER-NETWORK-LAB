#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of frames: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "\nSending Frame " << i << endl;
        cout << "Waiting for ACK..." << endl;

        char ack;
        cout << "Enter ACK (Y for received / N for lost): ";
        cin >> ack;

        while (ack == 'N' || ack == 'n') {
            cout << "ACK lost! Resending Frame " << i << endl;

            cout << "Enter ACK (Y for received / N for lost): ";
            cin >> ack;
        }

        cout << "ACK received for Frame " << i << endl;
    }

    cout << "\nAll frames transmitted successfully!" << endl;

    return 0;
}