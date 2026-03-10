#ifndef SUBJECTSERVICE_CLASS_H
#define SUBJECTSERVICE_CLASS_H

#include <vector>

#include <core/domain/Subject.h>
#include <core/repositories/ISubjectRepository.h>

class SubjectService {
    public:
        explicit SubjectService(ISubjectRepository& repo);
        int CreateSubject(const Subject& subject);
        std::vector<Subject> GetSubjects();
        void UpdateSubject(const Subject& subject);
        void RemoveSubject(int id);
    private:
        ISubjectRepository& m_repo;
};

#endif

