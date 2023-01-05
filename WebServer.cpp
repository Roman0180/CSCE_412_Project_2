#include <string>
using namespace std;
#include "Request.cpp"
/**
 * @brief This class represents a web server
 * This class has fields to store the number of active requests, the finished time of the current request, the current request, and the number of finished requests. It also has a constructor to initialize these fields and a method to reply to a client.
 */
class WebServer
{
public:
    /// @brief The number of active requests
    int activeRequests;
    /// @brief The finished time of the current request
    int finishedTime;
    /// @brief The current request
    Request currRequest;
    /// @brief The number of finished requests
    int finishedRequests;
    /**
     * @brief Construct a new Web Server object
     * This constructor initializes the activeRequests, finishedTime, currRequest, and finishedRequests fields to 0, 0, an empty Request object, and 0, respectively.
     */
    WebServer() : activeRequests(0), finishedTime(0), currRequest(), finishedRequests(0){};
    /**
     @brief Replies to a client
    * This function prints a message indicating that the server has finished processing a request if the current clock cycle is greater than the finished time of the current request and the server has active requests. It also decreases the activeRequests field by 1, sets the currRequest field to an empty Request object, and increases the finishedRequests field by 1.
    * @param currClockCycle The current clock cycle
    * @param serverNum The number of the server
     */
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