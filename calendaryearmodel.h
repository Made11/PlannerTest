#ifndef CALENDARYEARMODEL_H
#define CALENDARYEARMODEL_H

#include "calendar.h"
#include <QAbstractTableModel>

class CalendarYearModel : public QAbstractTableModel
{
public:
    struct CellData {
        bool bValid;
        QDate day;
        QString type;
    };
    enum Role {
      DateRole = Qt::UserRole + 1,
    };
    explicit CalendarYearModel(QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    void setCalendarYear(int iYear);
    void addEntry(QString sEntry, QList<QPair<QDate,QDate> > liDates);
    void addEntry(QString sEntry, QModelIndex miIndex);

private:
    int _iYear;
    QList<int> _liFirstDayOffset;
    QList<QList<CalendarYearModel::CellData> > _liData;

    // QAbstractItemModel interface
public:
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;



    // QAbstractItemModel interface
public:
    Qt::ItemFlags flags(const QModelIndex &index) const;
};

Q_DECLARE_METATYPE(CalendarYearModel::CellData)

#endif // CALENDARYEARMODEL_H
