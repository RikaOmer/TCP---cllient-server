#ifndef CLICLASS
#define CLICLASS

#include <string>
#include <vector>
#include "Command.h"
#include "DefaultIO.h"

using namespace std;

class CLI
{
private:
    bool flag; // when to exit
    DefaultIO *dio; // choose IO 
    list<string> data = {}; // unclassified data
    map<string, list<vector<double>>> dataSet = {}; // classified data
    vector<Command *> commands; // all commands
    int k = 5; // k for the Knn
    string dm = "AUC"; // function for Knn
    vector<string> names = {};  //classified names
    int menu();

public:
    CLI(DefaultIO *dio);
    void start();
};
#endif