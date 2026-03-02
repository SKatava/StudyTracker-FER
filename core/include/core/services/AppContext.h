#ifndef APPCONTEXT_CLASS_H
#define APPCONTEXT_CLASS_H

#include <core/persistence/Database.h>

class AppContext {
    public:
        explicit AppContext();

    private:
        Database m_db;
};

#endif

