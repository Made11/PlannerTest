#include "requestentry.h"
#include "qcolor.h"

RequestEntry::RequestEntry()
{

}


QDate RequestEntry::getFromDate() const
{
    return Request::getRequestTimePeriod().first;
}

QDate RequestEntry::getToDate() const
{
    return Request::getRequestTimePeriod().second;
}

QColor RequestEntry::getColor() const
{
    return Qt::green;

    //    switch (_requestType) {
    //    case Vecation:
    //        return Qt::blue;
    //    case MobileWorking:
    //        return Qt::yellow;
    //    case RoomBooking:
    //        return Qt::green;
    //    }
}

bool RequestEntry::isReleased() const
{
    return true;
}

