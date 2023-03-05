#ifndef ABSTRACTCALENDARENTRY_H
#define ABSTRACTCALENDARENTRY_H


#include "qdatetime.h"

class AbstractCalendarEntry
{
public:
    AbstractCalendarEntry();

    virtual QDate getFromDate() const = 0;
    virtual QDate getToDate() const = 0;
    virtual QColor getColor() const = 0;
    virtual bool isReleased() const = 0;
};

#endif // ABSTRACTCALENDARENTRY_H
