#ifndef IOL_GLOBAL_H
#define IOL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(IOLCALC_LIBRARY)
#  define IOLCALC_EXPORT Q_DECL_EXPORT
#else
#  define IOLCALC_EXPORT Q_DECL_IMPORT
#endif

#endif // IOL_GLOBAL_H
