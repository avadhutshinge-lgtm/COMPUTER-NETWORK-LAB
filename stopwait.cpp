#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int n;

    cout << "Enter number of frames: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Please enter a valid number of frames.";
        return 0;
    }

    srand(time(0));

    // Randomly select one frame to be lost
    int lostFrame = (rand() % n) + 1;

    int frame = 1;

    while (frame <= n)
    {
        cout << "\n----------------------------------------";
        cout << "\nFRAME " << frame << " START";
        cout << "\n----------------------------------------\n";

        cout << "Sender   : Sending Frame " << frame << "...\n";

        if (frame == lostFrame)
        {
            cout << "Channel  : Frame " << frame << " LOST!\n";
            cout << "Sender   : Waiting for ACK...\n";
            cout << "Sender   : TIMEOUT!\n";
            cout << "Sender   : No ACK received.\n";
            cout << "Sender   : Retransmitting Frame " << frame << "...\n";

            cout << "Receiver : Frame " << frame << " received successfully.\n";
            cout << "Receiver : Sending ACK " << frame << "...\n";
            cout << "Sender   : ACK " << frame << " received.\n";
        }
        else
        {
            cout << "Receiver : Frame " << frame << " received successfully.\n";
            cout << "Receiver : Sending ACK " << frame << "...\n";
            cout << "Sender   : ACK " << frame << " received.\n";
        }

        cout << "Frame " << frame << " completed successfully.\n";

        frame++;
    }

    cout << "\n========================================";
    cout << "\nALL FRAMES TRANSMITTED";
    cout << "\n========================================\n";

    return 0;
}