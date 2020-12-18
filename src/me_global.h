#ifndef ME_GLOBAL_H
#define ME_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ME_LIBRARY)
#  define MESHARED_EXPORT Q_DECL_EXPORT
#else
#  define MESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ME_GLOBAL_H
