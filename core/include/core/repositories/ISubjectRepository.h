#ifndef ISUBJECTREPOSITORY_CLASS_H
#define ISUBJECTREPOSITORY_CLASS_H

#include <core/domain/Subject.h>

#include <vector>

class ISubjectRepository {
public:
    virtual ~ISubjectRepository() = default;

    virtual int Add(const Subject& subject) = 0;
    virtual std::vector<Subject> GetAll() = 0;
    virtual void Update(const Subject& subject) = 0;
    virtual void Remove(int id) = 0;
};

#endif
