#include <string>
using namespace std; 
#include "Request.cpp"


class WebServer{
    public: 
        int activeRequests; 
        int finishedTime; 
        Request currRequest; 

        WebServer() : activeRequests(0), finishedTime(0), currRequest() {}; 
        string response(Request requestPacket){

            // after time has elapsed in the request packet, flip the request to be empty and send the response to the server
            this->activeRequests -= 1; 
            return ""; 
        }
}; 