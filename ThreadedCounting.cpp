#include <iostream>
#include <thread>   
#include <atomic>  
#include <chrono>   
#include <sstream> 

// Atomic bpplean variable to control the start of countdown
std::atomic<bool> startCountdown(false);

// Helper function to get the current thread ID as a string
std::string getThreadId() 
{
    // Create a string stream
    std::ostringstream oss;        

    // Get the thread ID and insert it into the stream  
    oss << std::this_thread::get_id(); 

    // Convert the stream to a string and return it
    return oss.str();                

}// END getThreadId

// Function to count up from 1 to 20
void countUp() 
{
    for (int i = 1; i <= 20; ++i) 
    {
        // Print the current thread ID and count up value
        std::cout << "Count Up: " << i << "| Thread ID: [" << getThreadId() << "]" << std::endl;
        
        // Sleep for 100 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); 

    } // CountUp

    startCountdown = true; // Set atomic variable to true 

} // END CountUp

// Function to count down from 20 to 0
void countDown() 
{
    // Wait until startCountdown is set to true
    while (!startCountdown) 
    {
        // Sleep for 50 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); 

    } // END while

    for (int i = 20; i >= 0; --i) 
    {
        // Print the current thread ID and count down value
        std::cout << "Count Down: " << i << "| Thread ID: [" << getThreadId() << "]" << std::endl;
        
        // Sleep for 100 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); 

    } // END for

} // EN CountDown

// Main function where the program execution begins
int main() 
{    
    std::thread t1(countUp); // Create a thread to run countUp
    std::thread t2(countDown); // Create a thread to run countDown 

    t1.join(); // Wait for thread t1 to finish
    t2.join(); // Wait for thread t2 to finish

    return 0; // Return value fopr main function
}
