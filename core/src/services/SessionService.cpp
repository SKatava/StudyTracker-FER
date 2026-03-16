#include <core/services/SessionService.h>
#include <algorithm>


SessionService::SessionService(ISessionRepository& repo) 
    :   m_repo(repo)
{}

int SessionService::CreateSession(const Session& session) {
    return m_repo.Add(session);
}

std::vector<Session> SessionService::GetSessions() {
    return m_repo.GetAll();
}

std::vector<Session> SessionService::GetSessionsSortedByDate() {
    auto sessions = m_repo.GetAll();

    std::sort(sessions.begin(), sessions.end(), [](const Session& a, const Session& b) {
        if(a.GetYear() != b.GetYear()) return a.GetYear() < b.GetYear();
        if(a.GetMonth() != b.GetMonth()) return a.GetMonth() < b.GetMonth();
        return a.GetDay() < b.GetDay();
     });

    return sessions;
}

void SessionService::RemoveSession(int id) {
    m_repo.Remove(id);
}
