#include <Windows.h>
#include <thread>
#include <chrono>

// Function to simulate pressing Ctrl + S
void pressCtrlS() {
    // Press Ctrl
    keybd_event(VK_CONTROL, 0, 0, 0);
    // Press S
    keybd_event('S', 0, 0, 0);
    // Release S
    keybd_event('S', 0, KEYEVENTF_KEYUP, 0);
    // Release Ctrl
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
}

int main() {
    // Set the interval for saving (in milliseconds)
    int interval = 10000; // 10 seconds

    // Loop indefinitely
    while (true) {
        // Simulate Ctrl + S keypress
        pressCtrlS();

        // Wait for the specified interval
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    }
    return 0;
}
