#include <core/services/AppContext.h>

AppContext::AppContext() {
    m_db.InitializeSchema();
}
