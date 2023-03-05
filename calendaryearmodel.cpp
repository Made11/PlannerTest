#include "calendaryearmodel.h"
#include "qforeach.h"

CalendarYearModel::CalendarYearModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}


int CalendarYearModel::rowCount(const QModelIndex &parent) const
{
    return _liData.size();
}

int CalendarYearModel::columnCount(const QModelIndex &parent) const
{
    return 37;
}

QVariant CalendarYearModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) {
        return QVariant();
    }

    if(role == DateRole) {
        const int firstDayOfMonth = QDate(_iYear,index.row()+1,1).dayOfWeek();
        const int iDay = index.column()+1-(firstDayOfMonth-1);
        QDate currentDay = QDate(_iYear,index.row()+1,iDay);
        if(currentDay.isValid()) {
//            return currentDay;
        }
        return QVariant::fromValue(_liData[index.row()][index.column()]);
//        return QDate();
    }

    return QVariant();
}

void CalendarYearModel::setCalendarYear(int iYear)
{
    this->beginResetModel();
    _iYear = iYear;
    for (int iMonth = 1; iMonth <= 12; ++iMonth) {
        QList<CalendarYearModel::CellData> dataList;
        const int firstDayOfMonthOffset = QDate(_iYear,iMonth,1).dayOfWeek()-1;
        _liFirstDayOffset.append(firstDayOfMonthOffset);
        for (int iDay = 1; iDay <= 37; ++iDay) {
            CalendarYearModel::CellData rowData;
            rowData.day = QDate(_iYear,iMonth,iDay-firstDayOfMonthOffset);
            rowData.bValid = rowData.day.isValid();

            dataList.append(rowData);
        }
        _liData.append(dataList);
    }
    this->endResetModel();
}

void CalendarYearModel::addEntry(QSharedPointer<AbstractCalendarEntry> spCalEntry, QList<QPair<QDate, QDate> > liDates)
{
    foreach (auto dateRange, liDates) {
        for (int var = 0; var < dateRange.first.daysTo(dateRange.second) + 1; ++var) {
            QDate d = dateRange.first.addDays(var);
            _liData[d.month()-1][d.day()-1+_liFirstDayOffset[d.month()-1]].spCalEntry = spCalEntry;
        }
    }
}

void CalendarYearModel::addEntry(QString sEntry, QModelIndex miIndex)
{
    if(_liData[miIndex.row()][miIndex.column()].bValid) {
        _liData[miIndex.row()][miIndex.column()].type = sEntry;
    }
    emit this->dataChanged(miIndex,miIndex);
}

void CalendarYearModel::addEntry(QSharedPointer<AbstractCalendarEntry> spCalEntry)
{
    this->addEntry(spCalEntry,QList<QPair<QDate, QDate> >() << qMakePair(spCalEntry->getFromDate(), spCalEntry->getToDate()));
}





QVariant CalendarYearModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        return QLocale().dayName(section % 7 + 1, QLocale::ShortFormat);
    }

    if(role == Qt::DisplayRole && orientation == Qt::Vertical) {
        return QLocale().monthName(section+1, QLocale::ShortFormat);
    }

    return QVariant();
}


Qt::ItemFlags CalendarYearModel::flags(const QModelIndex &index) const
{
    if(_liData[index.row()][index.column()].bValid) {
        return QAbstractTableModel::flags(index);
    }
    return Qt::NoItemFlags;
}
