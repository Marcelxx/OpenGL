#ifndef OPENGLLIB_GLOBAL_H
#define OPENGLLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef OPENGLLIB_LIB
# define OPENGLLIB_EXPORT Q_DECL_EXPORT
#else
# define OPENGLLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // OPENGLLIB_GLOBAL_H
