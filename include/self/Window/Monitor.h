#ifndef __MONITOR_H__
#define __MONITOR_H__
#include <windows.h>

class ProcessMonitor {
private:
    HANDLE processHandle;
    ULARGE_INTEGER lastCPUUsage;
    ULARGE_INTEGER lastSystemTime;
    
public:
    // Constructor and destructor
    ProcessMonitor();
    ~ProcessMonitor();
    
    // Get CPU usage percentage of the current process
    double getProcessCpuUsage();
    
    // Get RAM usage of the current process in MB
    double getProcessMemoryUsage();
    
    // Get virtual memory usage of the current process in MB
    double getProcessVirtualMemoryUsage();
};

#endif // __MONITOR_H__