#ifndef REQUESTENTRY_H
#define REQUESTENTRY_H


#include "abstractcalendarentry.h"
#include "request.h"
class RequestEntry : public Request, public AbstractCalendarEntry
{
public:
    RequestEntry();

    // AbstractCalendarEntry interface
public:
    QDate getFromDate() const;
    QDate getToDate() const;
    QColor getColor() const;
    bool isReleased() const;
};

#endif // REQUESTENTRY_H
