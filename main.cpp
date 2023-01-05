#include <iostream>
#include <numeric>
#include "LoadBalancer.cpp"
using namespace std;

/// @brief THIS FUNCTION WAS GENERATED BY CHATGPT: A function to randomly generate true or false
/// @return True or False
bool getRandomBool()
{
    return rand() % 2 == 0;
}

int main()
{
    srand(time(0));
    int numWebServers;
    cout << "Enter the number of desired servers: ";
    cin >> numWebServers;
    int totalClockCycles;
    cout << "Enter the desired number of clock cycles: ";
    cin >> totalClockCycles;
    int taskLower, taskUpper; 
    cout << "Enter the lower bound for task times (in clock cycles): "; 
    cin >> taskLower; 
    cout << "Enter the upper bound for task times (in clock cycles): "; 
    cin >> taskUpper; 
    // set up the LoadBalancer with the appropriate number of web servers, total clock cycles, and a full queue
    LoadBalancer loadBalancer(totalClockCycles);
    for (int i = 0; i < numWebServers; i++)loadBalancer.webServers.push_back(WebServer());
    for (int i = 0; i < numWebServers * 20; i++)loadBalancer.queue.push(Request(taskLower, taskUpper)); // fill the queue
    loadBalancer.numRequestsReceived = loadBalancer.queue.size();
    while (!loadBalancer.queue.empty() && loadBalancer.currClockCycle <= loadBalancer.maxClockCycles)
    {
        loadBalancer.currClockCycle += 2;
        // have the load balancer send all requests to available webservers
        loadBalancer.sendToWebserver();
        // check to see if any requests have finished
        for (int i = 0; i < loadBalancer.webServers.size(); i++) loadBalancer.webServers.at(i).replyToClient(loadBalancer.currClockCycle, i + 1);
        // randomly choose if a new element should be added if the queue is not full
        if (getRandomBool() && loadBalancer.queue.size() < numWebServers * 20)
        {
            loadBalancer.queue.push(Request(taskLower, taskUpper));
            loadBalancer.numRequestsReceived += 1;
        }
    }
    cout << "Starting Queue size was " << numWebServers * 20 << endl;
    cout << "Ending Queue size was " << loadBalancer.queue.size() << endl;
    cout << "The range of task times was between " << taskLower << " and " << taskUpper << " clock cycles" << endl; 
}