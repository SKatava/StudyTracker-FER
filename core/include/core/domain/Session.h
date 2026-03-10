#ifndef STUDYSESSION_STRUCT_H
#define STUDYSESSION_STRUCT_H

#include <string>
#include <cstdint>

struct Session {
    int32_t         id              {-1};
    int32_t         subjectId       {-1};
    uint32_t        minutes         {0}; 
    std::string     date            {"UNKNOWN"};
    std::string     description     {"UNKNOWN"};
};

#endif
