#include <string>
using namespace std; 
#include "Request.cpp"


class WebServer{
    public: 
        int activeRequests; 
        WebServer() : activeRequests(0) {}; 
        string response(Request requestPacket){
            // after time has elapsed in the request packet, flip the request to be empty and send the response to the server
            return ""; 
        }
}; 