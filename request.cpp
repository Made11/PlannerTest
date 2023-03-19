#include "request.h"
#include "qcolor.h"

Request::Request(QObject *parent) : QObject(parent)
{

}

Request::Type Request::getRequestType() const
{
    return _requestType;
}

void Request::setRequestType(Type newRequestType)
{
    if (_requestType == newRequestType)
        return;
    _requestType = newRequestType;
    emit requestTypeChanged();
}

QPair<QDate, QDate> Request::getRequestTimePeriod() const
{
    return _requestTimePeriod;
}

void Request::setRequestTimePeriod(const QPair<QDate, QDate> &newRequestTimePeriod)
{
    if (_requestTimePeriod == newRequestTimePeriod)
        return;
    _requestTimePeriod = newRequestTimePeriod;
    emit requestTimePeriodChanged();
}


//QDate Request::getFromDate() const
//{
//    return _requestTimePeriod.first;
//}

//QDate Request::getToDate() const
//{
//    return _requestTimePeriod.second;
//}

//QColor Request::getColor() const
//{
//    switch (_requestType) {
//    case Vecation:
//        return Qt::blue;
//    case MobileWorking:
//        return Qt::yellow;
//    case RoomBooking:
//        return Qt::green;
//    }
//}

//bool Request::isReleased() const
//{
//    return true;
//}
