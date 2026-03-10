#ifndef ISESSIONREPOSITORY_CLASS_H
#define ISESSIONREPOSITORY_CLASS_H

#include <core/domain/Session.h>

#include <vector>

class ISessionRepository {
public:
    virtual ~ISessionRepository() = default;

    virtual int Add(const Session& session) = 0;
    virtual std::vector<Session> GetAll() = 0;
    virtual void Remove(int id) = 0;
};

#endif
