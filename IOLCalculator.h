#ifndef IOLCALCULATOR_H
#define IOLCALCULATOR_H

#include "iol_global.h"
#include <QString>
#include <array>

namespace iol {

enum class Formula {
    SRKT      = 0,
    SRKII     = 1,
    HofferQ   = 2,
    Holladay  = 3,
    Binkhorst = 4
};

struct Input {
    Formula formula     = Formula::SRKT;
    double  axialLength = 0.0;
    double  aConstant   = 0.0;
    double  k           = 0.0;
    double  targetRx    = 0.0;
};

struct Result {
    bool                  valid       = false;
    double                pEmmetropia = 0.0;
    std::array<double, 5> iolPower    {};
    std::array<double, 5> predictedRx {};
};

class IOLCALC_EXPORT IOLCalculator {
public:
    IOLCalculator();
    Result calculate(const Input &in) const;
    static QString formulaName(Formula f);
    static QString version();
};

} // namespace iol

#endif // IOLCALCULATOR_H
