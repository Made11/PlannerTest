#ifndef CALENDAR_H
#define CALENDAR_H

#include <QDate>



class Calendar
{
public:
    Calendar();

    QDate getStartDate() const;
    void setStartDate(const QDate &newStartDate);

    QDate getEndDate() const;
    void setEndDate(const QDate &newEndDate);

private:
    QDate _startDate;
    QDate _endDate;
};

#endif // CALENDAR_H
