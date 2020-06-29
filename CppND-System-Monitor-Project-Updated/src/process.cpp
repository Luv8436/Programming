#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;
using namespace LinuxParser;

// TODO: Return this process's ID
int Process::Pid() { return pid_;}

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() {
    std::ifstream filestream(kProcDirectory+ to_string(Pid())+kStatFilename);
    int cpuUtilization = 0;
    if(filestream.is_open()) {
        std::string line;
        std::string value;
        int i =1;
        while (std::getline(filestream , line)){
            std::istringstream linestream(line);
            while(linestream >> value) {
                if( i == 14 || i == 15 || i == 16 || i == 17 || i == 22)
                {
                    cpuUtilization += std::stof(value);
                }
                i++;
                if(i > 22)
                {
                    break;
                }
            }

        }
    }
    return cpuUtilization / 5;
}

// TODO: Return the command that generated this process
string Process::Command() {
    std::ifstream filestream(kProcDirectory+ to_string(Pid())+kCmdlineFilename);
    string line;
    if(filestream.is_open()) {
        std::getline(filestream , line);
    }
    return line;
}

// TODO: Return this process's memory utilization
string Process::Ram() {
    std::ifstream filestream(kProcDirectory+ to_string(Pid())+kStatusFilename);
    string value;
    string unit;
    if(filestream.is_open()){
        string line;
        string key;
        while(std::getline(filestream , line)) {
            std::istringstream linestream(line);
            linestream >> key >> value >> unit ;
            if (key == "VmSize:")
            {
                break;
            }
        }
    }
    return value+" "+ unit;
}

// TODO: Return the user (name) that generated this process
string Process::User() {return LinuxParser::User(Pid());}

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(Pid()); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a[[maybe_unused]]) const { return true; }