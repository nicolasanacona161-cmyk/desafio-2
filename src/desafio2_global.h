#ifndef DESAFIO2_GLOBAL_H
#define DESAFIO2_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DESAFIO2_LIBRARY)
#define DESAFIO2_EXPORT Q_DECL_EXPORT
#else
#define DESAFIO2_EXPORT Q_DECL_IMPORT
#endif

#endif // DESAFIO2_GLOBAL_H
