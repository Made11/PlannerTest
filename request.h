#ifndef REQUEST_H
#define REQUEST_H

#include <QObject>
#include <QDate>
#include <abstractcalendarentry.h>

class Request : public QObject, public AbstractCalendarEntry
{
    Q_OBJECT
    Q_PROPERTY(Type requestType READ getRequestType WRITE setRequestType NOTIFY requestTypeChanged)
    Q_PROPERTY(QPair<QDate, QDate> requestTimePeriod READ getRequestTimePeriod WRITE setRequestTimePeriod NOTIFY requestTimePeriodChanged)

public:
    enum Type {
        Vecation, MobileWorking, RoomBooking
    };
    Request(QObject *parent = nullptr);
    Type getRequestType() const;
    void setRequestType(Type newRequestType);

    QPair<QDate, QDate> getRequestTimePeriod() const;
    void setRequestTimePeriod(const QPair<QDate, QDate> &newRequestTimePeriod);

signals:
    void requestTypeChanged();

    void requestTimePeriodChanged();

private:
    Type _requestType;
    QPair<QDate, QDate> _requestTimePeriod;


    // AbstractCalendarEntry interface
public:
    QDate getFromDate() const;
    QDate getToDate() const;
    QColor getColor() const;
    bool isReleased() const;
};

#endif // REQUEST_H
