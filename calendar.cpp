#include "calendar.h"

Calendar::Calendar()
{

}

QDate Calendar::getStartDate() const
{
    return _startDate;
}

void Calendar::setStartDate(const QDate &newStartDate)
{
    _startDate = newStartDate;
}

QDate Calendar::getEndDate() const
{
    return _endDate;
}

void Calendar::setEndDate(const QDate &newEndDate)
{
    _endDate = newEndDate;
}
