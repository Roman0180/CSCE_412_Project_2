#include <iostream>
#include "LoadBalancer.cpp"
using namespace std; 

/// @brief THIS FUNCTION WAS GENERATED BY CHATGPT: A function to randomly generate true or false
/// @return True or False
bool getRandomBoolean() {
  // set initial seed value to system clock
  srand(static_cast<unsigned int>(time(0)));
  // generate a random number between 0 and 1
  int randomNumber = rand() % 2;
  return randomNumber == 1;
}
int main(){
    int numWebServers; 
    cout << "Enter the number of desired servers: "; 
    cin >> numWebServers; 
    int totalClockCycles; 
    cout << "Enter the desired number of clock cycles: "; 
    cin >> totalClockCycles; 
    // set up the LoadBalancer with the appropriate number of web servers, total clock cycles, and a full queue
    LoadBalancer loadBalancer(totalClockCycles); 
    for(int i = 0; i < numWebServers; i++) loadBalancer.webServers.push_back(WebServer()); 
    for(int i = 0; i < numWebServers * 20; i++) loadBalancer.queue.push(Request(0, loadBalancer.maxClockCycles)); 
    while(!loadBalancer.queue.empty()){
        // have the load balancer send all requests to available webservers
        loadBalancer.sendToWebserver();
        // check to see if any new requests have arrived
        if (getRandomBoolean()){ // randomly choose if a new element should be added
            loadBalancer.queue.push(Request(loadBalancer.currClockCycle, loadBalancer.maxClockCycles));
        }
        loadBalancer.queue.pop();
    }
    cout << "finished" << endl; 

//QUESTIONS: what if max clock cycle -1 is selected for multiple packets 
    

}