#include <string>
#include <queue>
#include <vector>
#include <algorithm>  // for std::min_element()
#include <iostream>
#include "WebServer.cpp"

using namespace std; 
bool compareWebServers(WebServer a, WebServer b) {
   return a.activeRequests < b.activeRequests;
}
class LoadBalancer{
    public:
        queue<Request> queue;  
        vector<WebServer> webServers; 
        int currClockCycle;
        int maxClockCycles; 
        LoadBalancer(int maxTime) : currClockCycle(0), maxClockCycles(maxTime) {}; 

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
                    this->webServers.at(i).finishedTime = this->currClockCycle + request.timeToProcess; 
                }
            }
            
        }
        void checkForResponse(){
            for(int i = 0; i < this->webServers.size(); i++){
                if(this->currClockCycle > this->webServers.at(i).finishedTime && this->webServers.at(i).activeRequests > 0){
                    cout << i << " Server finished at clock cycle " << this->webServers.at(i).finishedTime << endl;
                    this->webServers.at(i).activeRequests -= 1;  
                }
            }
        }
        
        

}; 