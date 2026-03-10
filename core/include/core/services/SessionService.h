#ifndef SESSIONSERVICE_CLASS_H
#define SESSIONSERVICE_CLASS_H

#include <vector>

#include <core/domain/Session.h>
#include <core/repositories/ISessionRepository.h>

class SessionService {
    public:
        explicit SessionService(ISessionRepository& repo);
        int CreateSession(const Session& session);
        std::vector<Session> GetSessions();
        void UpdateSession(const Session& session);
        void RemoveSession(int id);
    private:
        ISessionRepository& m_repo;
};

#endif
