#ifndef TASK_CLASS_H
#define TASK_CLASS_H

#include <cstdint>
#include <string>

struct Task {
    int32_t         id          {-1}; 
    int32_t         subjectId   {-1};
    uint32_t        minutes     {0};
    bool            done        {false};
    std::string     description {"UNKNOWN"};
    std::string     date_start  {"UNKNOWN"};
    std::string     date_done   {"UNKNOWN"};
    std::string     date_end    {"UNKNOWN"};

};

#endif
