#ifndef DESAFIO__2_GLOBAL_H
#define DESAFIO__2_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DESAFIO__2_LIBRARY)
#define DESAFIO__2_EXPORT Q_DECL_EXPORT
#else
#define DESAFIO__2_EXPORT Q_DECL_IMPORT
#endif

#endif // DESAFIO__2_GLOBAL_H
