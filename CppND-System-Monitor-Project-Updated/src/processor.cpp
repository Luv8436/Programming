#include "processor.h"

#include "linux_parser.h"
#include <chrono>
#include <thread>
using namespace LinuxParser;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;


using std::stof;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {

   prev_ = LinuxParser::CpuUtilization();
    float PrevIdle = stof(prev_[4]) + stof(prev_[5]);
    float PrevNonIdle = stof(prev_[1]) + stof(prev_[2]) + stof(prev_[3]) + stof(prev_[6]) + stof(prev_[7]) + stof(prev_[8]);
    float PrevTotal = PrevIdle + PrevNonIdle;

    //user    nice   system  idle      iowait irq   softirq  steal  guest  guest_nice
    sleep_for(10ns);
    sleep_until(system_clock::now() + 1s);

    curr_ = LinuxParser::CpuUtilization();


    float curr_idle = stof(curr_[4]) + stof(curr_[5]);
    float NonIdle = stof(curr_[1]) + stof(curr_[2]) + stof(curr_[3]) + stof(curr_[6]) + stof(curr_[7]) + stof(curr_[8]);
    float Total = curr_idle + NonIdle;



    // differentiate: actual value minus the previous one
    float totald = Total - PrevTotal;
    float idled = curr_idle - PrevIdle;
    float CPU_Percentage = (totald - idled)/totald;
    return CPU_Percentage;

}