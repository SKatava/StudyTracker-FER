#include <core/services/SubjectService.h>

SubjectService::SubjectService(ISubjectRepository& repo) 
    :   m_repo(repo)
{}

int SubjectService::CreateSubject(const Subject& subject) {
    return m_repo.Add(subject);
}

std::vector<Subject> SubjectService::GetSubjects() {
    return m_repo.GetAll();
}

void SubjectService::UpdateSubject(const Subject& subject) {
    m_repo.Update(subject);
}

void SubjectService::RemoveSubject(int id) {
    m_repo.Remove(id);
}
