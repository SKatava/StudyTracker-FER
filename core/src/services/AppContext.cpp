#include <core/services/AppContext.h>

AppContext::AppContext(std::unique_ptr<ISubjectRepository> subjectRepo) 
    :   m_subjectRepo(std::move(subjectRepo)),
        m_subjectService(*m_subjectRepo)
{}

SubjectService& AppContext::Subjects() {
    return m_subjectService;
}
