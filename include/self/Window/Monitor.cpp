#include "Monitor.h"
#include <psapi.h>

ProcessMonitor::ProcessMonitor() {
    // Get current process handle
    processHandle = GetCurrentProcess();
    
    // Initialize CPU usage tracking
    lastCPUUsage.QuadPart = 0;
    lastSystemTime.QuadPart = 0;
    
    // First call to initialize values
    getProcessCpuUsage();
}

ProcessMonitor::~ProcessMonitor() {
    if (processHandle != NULL) {
        CloseHandle(processHandle);
    }
}

double ProcessMonitor::getProcessCpuUsage() {
    FILETIME createTime, exitTime, kernelTime, userTime;
    if (!GetProcessTimes(processHandle, &createTime, &exitTime, &kernelTime, &userTime)) {
        return -1.0;
    }
    
    ULARGE_INTEGER now;
    GetSystemTimeAsFileTime((FILETIME*)&now);
    
    ULARGE_INTEGER kernelTimeValue;
    kernelTimeValue.LowPart = kernelTime.dwLowDateTime;
    kernelTimeValue.HighPart = kernelTime.dwHighDateTime;
    
    ULARGE_INTEGER userTimeValue;
    userTimeValue.LowPart = userTime.dwLowDateTime;
    userTimeValue.HighPart = userTime.dwHighDateTime;
    
    ULARGE_INTEGER cpuUsage;
    cpuUsage.QuadPart = kernelTimeValue.QuadPart + userTimeValue.QuadPart;
    
    double percent = 0.0;
    
    if (lastCPUUsage.QuadPart != 0) {
        ULONGLONG cpuDiff = cpuUsage.QuadPart - lastCPUUsage.QuadPart;
        ULONGLONG timeDiff = now.QuadPart - lastSystemTime.QuadPart;
        
        if (timeDiff > 0) {
            percent = (cpuDiff * 100.0) / timeDiff;
            // Adjust for the number of cores (as Process CPU usage can exceed 100% with multiple cores)
            SYSTEM_INFO sysInfo;
            GetSystemInfo(&sysInfo);
            percent /= sysInfo.dwNumberOfProcessors;
        }
    }
    
    lastCPUUsage.QuadPart = cpuUsage.QuadPart;
    lastSystemTime.QuadPart = now.QuadPart;
    
    return percent;
}

double ProcessMonitor::getProcessMemoryUsage() {
    PROCESS_MEMORY_COUNTERS_EX pmc;
    if (GetProcessMemoryInfo(processHandle, (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc))) {
        // Return working set size (physical memory used by process) in MB
        return static_cast<double>(pmc.WorkingSetSize) / (1024 * 1024);
    }
    return -1.0;
}

double ProcessMonitor::getProcessVirtualMemoryUsage() {
    PROCESS_MEMORY_COUNTERS_EX pmc;
    if (GetProcessMemoryInfo(processHandle, (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc))) {
        // Return private usage (committed virtual memory) in MB
        return static_cast<double>(pmc.PrivateUsage) / (1024 * 1024);
    }
    return -1.0;
}