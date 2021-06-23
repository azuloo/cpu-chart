#ifndef CPUDATAPROVIDER_H
#define CPUDATAPROVIDER_H

#include <QWidget>
#include <unistd.h>
#include <sys_monitor_api.h>

class CPUDataProvider
{
public:
    CPUDataProvider() = default;
    ~CPUDataProvider() = default;

    inline static double getCPUTempByIdx(int i) { return get_core_temp_by_idx(i); }
    inline static long getCPUNum() { return get_core_num(); }
};

#endif // CPUDATAPROVIDER_H
