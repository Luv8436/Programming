#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() {
  double total_mem , free_mem;
  std::ifstream filestream(kProcDirectory+kMeminfoFilename);
    if (filestream.is_open()) {
      string line;
      string key;
      string value;
      while(getline(filestream , line)) {
        std::istringstream linestream(line);
        linestream >> key >> value;
        if (key == "MemTotal:") {
          total_mem = stof(value);
        }
        if (key == "MemFree:") {
          free_mem = stof(value);
          break;
        }
      }
    }
    return  ((total_mem - free_mem)/total_mem) ;
}

// TODO: Read and return the system uptime
long LinuxParser::UpTime() {
  long double totalTime;
  long double idleTime;
  std::ifstream filestream(kProcDirectory+kUptimeFilename);
  if (filestream.is_open()){
    string key;
    string value;
    string line;
    std::getline(filestream, line);
    std::istringstream linestream(line);
    linestream >> key >> value;
    totalTime = std::stof(key);
    idleTime = std::stof(value);
    }
  return (totalTime + idleTime)/sysconf(_SC_CLK_TCK);
}

// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() {
  float systemTime;
  std::ifstream filestream(kProcDirectory+kStatFilename);
  if (filestream.is_open()) {
    string line;
    string value;
    std::getline(filestream , line);
    std::istringstream linestream(line);
    int i=0;
    while(linestream >> value) {
      if(i==3) {
        systemTime = std::stof(value);
        break;
      }
      i++;
    }
  }
  return systemTime/sysconf(_SC_CLK_TCK);
}

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid) {
  long activeJiffies;
  std::ifstream filestream(kProcDirectory+to_string(pid)+kStatFilename);
  if (filestream.is_open()) {
    string line;
    string value;
    int i=1;
    while(std::getline(filestream, line)) {
      std::istringstream linestream(line);
      while(linestream >> value ) {
        if(i==14 || i==15 || i==16 || i==17) {
          activeJiffies = activeJiffies + std::stof(value);
        }
        i++;
        if(i>17)
        break;
      }
    }
  }
  return activeJiffies/sysconf(_SC_CLK_TCK);
}

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() {
  float idleTime;
  float totalTime;
  std::ifstream filestream(kProcDirectory+kStatFilename);
  if (filestream.is_open()) {
    string line;
    string value;
    std::getline(filestream , line);
    std::istringstream linestream(line);
    int i=0;
    while(linestream >> value) {
      if(i==4) {
        idleTime = std::stof(value);
        break;
      }
      if(i==3) {
        totalTime = std::stof(value);
      }
      i++;
    }
  }
  return (totalTime - idleTime)/sysconf(_SC_CLK_TCK);
}

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() {
  std::ifstream filestream(kProcDirectory+kStatFilename);
  float idleTime;
  if (filestream.is_open()) {
    std::string line;
    std::string value;
    std::getline(filestream , line);
    std::istringstream linestream(line);
    int i=0;
    while(linestream >> value) {
      if(i==4) {
        idleTime = std::stof(value);
        break;
      }
      i++;
    }
  }
  return idleTime/sysconf(_SC_CLK_TCK);
}

// TODO: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() {
  std::ifstream filestream(kProcDirectory+kStatFilename);
  vector<string> cpu;
  if (filestream.is_open()) {
    string line;
    string value;
    std::getline(filestream , line);
    std::istringstream linestream(line);
    while(linestream >> value) {
      cpu.push_back(value);
    }
  }

  return cpu;
}

// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() {
  std::ifstream filestream(kProcDirectory+kStatFilename);
  string value;
  if (filestream.is_open()) {
    string line;
    string key;
    while(std::getline(filestream , line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if ( key == "processes")
      {
        break;
      }
    }
  }
  return std::stof(value);
}

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() {
  std::ifstream filestream(kProcDirectory+kStatFilename);
  string value;
  if (filestream.is_open()) {
    string line;
    string key;
    while(std::getline(filestream , line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if ( key == "procs_running")
      {
        break;
      }
    }
  }
  return std::stof(value);
}

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) {
  std::ifstream filestream(kProcDirectory+ to_string(pid)+kCmdlineFilename);
  string line;
  if (filestream.is_open()) {
    std::getline(filestream , line);
  }
  return line;
}

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid) {
  std::ifstream filestream(kProcDirectory+ to_string(pid)+kStatusFilename);
  string value;
  if (filestream.is_open()) {
    string line;
    string key;
    while (std::getline(filestream , line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if (key == "VmSize:") {
        break;
      }
    }
  }
  return value;
}

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid) {
  std::ifstream filestream(kProcDirectory+ to_string(pid)+kStatusFilename);
  string value;
  if (filestream.is_open()) {
    string line;
    string key;
    while (std::getline(filestream , line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if (key == "Uid:") {
        break;
      }
    }
  }
  return value;
}

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) {
  string uid = Uid(pid);
  std::ifstream filestream(kPasswordPath);
  string name;
    if(filestream.is_open()){
        string line;
        string x;
        string id;
        while(std::getline(filestream , line)) {
            std::replace(line.begin(), line.end(), ':', ' ');
            std::istringstream linestream(line);
            linestream >> name >> x >> id ;
            if (id == uid)
            {
                break;
            }
        }
    }
    return name;
}

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid) {
  std::ifstream filestream(kProcDirectory+ to_string(pid)+kStatFilename);
  string value;
  if (filestream.is_open()) {
    string line;
    int i=1;
    while (std::getline(filestream , line)) {
      std::istringstream linestream(line);
      while(linestream >> value)
      {
        if(i==22) {
          return std::stof(value)/sysconf(_SC_CLK_TCK);
        }
        i++;
      }
    }
  }
  return 0;
}