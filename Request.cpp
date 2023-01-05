#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <sstream>
#include <queue>

#include <random>
#include <string>
using namespace std;
/**

*@brief Generates a random alphanumeric string of a given length - created by ChatGPT
*@param length The length of the generated string (defaults to 25)
*@return A random alphanumeric string of the given length
*/
std::string generateRandomString(int length = 25)
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::string result;
    result.reserve(length);

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, sizeof(alphanum) - 2);

    for (int i = 0; i < length; ++i)
    {
        result += alphanum[distribution(generator)];
    }

    return result;
}

/// @brief A struct containing data for a request
struct RequestData
{
    /// @brief The data for the request
    string data;
    /// @brief Constructs a RequestData object. This constructor initializes the data field to a randomly generated string.
    RequestData() : data(generateRandomString()) {}
};
/// @brief A class representing a request. This class has fields for the incoming and outgoing IP addresses, the time it takes to process the request, and the request data. It also has a constructor to initialize these fields and methods to generate random IP addresses and process times.
class Request
{
public:
    /// @brief The incoming IP address
    string ipIn;
    /// @brief The outgoing IP address
    string ipOut;
    /// @brief The time it takes to process the request
    int timeToProcess;
    /// @brief The request data
    RequestData data;
    /// @brief Constructs an empty Request object
    Request(){};
    /**
     *@brief Constructs a Request object. This constructor initializes the ipIn, ipOut, and timeToProcess fields to random values and the data field to a RequestData object.
     *@param currTime The current time
     *@param maxTime The maximum time allowed
     */
    Request(int currTime, int maxTime) : ipIn(generateIPAddress()), ipOut(generateIPAddress()), timeToProcess(generateTimeToProcess(currTime, maxTime)), data(RequestData()){};
    ///@brief Generates a random IP address
    ///@return A random IP address
    string generateIPAddress()
    {
        stringstream ss;
        for (int i = 0; i < 4; i++)
        {
            int num = rand() % 256;
            ss << num;
            if (i < 3)
            {
                ss << ".";
            }
        }
        return ss.str();
    }
    /**
     * @brief Generates a random time it takes to process a request - created by ChatGPT
     *The process time will be less than or equal to the amount of clock cycles left.
     *@param min The minimum time allowed
     *@param max The maximum time allowed
     *@return The time it takes to process the request
     */
    int generateTimeToProcess(int min, int max)
    {
        // Generate a random number between min and max
        return rand() % (max - min + 1) + min;
    }
};