#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include "WebServer.cpp"

using namespace std; 
class LoadBalancer{
    public:
        queue<Request> queue;  
        vector<WebServer> webServers; 
        int currClockCycle;
        int maxClockCycles; 
        int numRequestsReceived; 
        LoadBalancer(int maxTime) : currClockCycle(0), maxClockCycles(maxTime), numRequestsReceived(0) {}; 
        /// @brief This function is responsible for sending a response to the web server and managing the reply
        void sendToWebserver(){
            // if a webserver is available, send a request to it
            for(int i = 0; i < this->webServers.size(); i++){
                if (this->webServers.at(i).activeRequests < 1){
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