#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include "WebServer.cpp"
using namespace std;
/// @brief This class represents a load balancer for a web server. This class is responsible for managing requests sent to the web server and distributing them to available web servers. It keeps track of the current clock cycle, the maximum number of clock cycles allowed, and the number of requests received. It also has a queue to store incoming requests and a vector of web servers.
class LoadBalancer
{
public:
    /// @brief A queue to store incoming requests
    queue<Request> queue;
    /// @brief A vector of web servers
    vector<WebServer> webServers;
    ///@brief The current clock cycle
    int currClockCycle;
    /// @brief The maximum number of clock cycles allowed
    int maxClockCycles;
    /// @brief The number of requests received
    int numRequestsReceived;
    /// @brief Constructs a LoadBalancer object
    LoadBalancer(int maxTime) : currClockCycle(0), maxClockCycles(maxTime), numRequestsReceived(0){};
    /**
     * @brief Sends a request to an available web server and manages the reply
     *
     * This function iterates through the web servers in the webServers vector. If a web server is available (i.e. has no active requests), it sends a request to it by popping it from the queue and setting the activeRequests and currRequest fields of the web server. It also sets the finishedTime field of the web server to the current clock cycle plus the time it takes to process the request.
     */
    void sendToWebserver()
    {
        // if a webserver is available, send a request to it
        for (int i = 0; i < this->webServers.size(); i++)
        {
            if (this->webServers.at(i).activeRequests < 1 && this->queue.size() > 0)
            {
                // pop from the queue
                Request request = this->queue.front();
                this->queue.pop();
                // show that the server is now busy
                this->webServers.at(i).activeRequests += 1;
                this->webServers.at(i).currRequest = request;
                this->webServers.at(i).finishedTime = this->currClockCycle + request.timeToProcess;
            }
        }
    }
};