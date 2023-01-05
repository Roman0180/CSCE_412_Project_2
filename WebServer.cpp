#include <string>
using namespace std;
#include "Request.cpp"

class WebServer
{
public:
    int activeRequests;
    int finishedTime;
    Request currRequest;
    int finishedRequests; 
    WebServer() : activeRequests(0), finishedTime(0), currRequest(), finishedRequests(0){};
    void replyToClient(int currClockCycle, int serverNum)
    {
        if (currClockCycle > this->finishedTime && this->activeRequests > 0)
        {
            cout << " Server " << serverNum << " finished at clock cycle " << this->finishedTime << " from " << this->currRequest.ipIn << " to " << this->currRequest.ipOut << endl;
            this->activeRequests -= 1;
            this->currRequest = Request();
            this->finishedRequests += 1; 
        }
    }
};