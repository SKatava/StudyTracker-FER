#include <core/services/SessionService.h>

SessionService::SessionService(ISessionRepository& repo) 
    :   m_repo(repo)
{}

int SessionService::CreateSession(const Session& session) {
    return m_repo.Add(session);
}

std::vector<Session> SessionService::GetSessions() {
    return m_repo.GetAll();
}

void SessionService::RemoveSession(int id) {
    m_repo.Remove(id);
}
