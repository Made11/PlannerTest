#ifndef CALENDARYEARDAYDELEGATE_H
#define CALENDARYEARDAYDELEGATE_H

#include <QStyledItemDelegate>

class CalendarYearDayDelegate : public QStyledItemDelegate
{
public:
    explicit CalendarYearDayDelegate(QObject *parent = nullptr);

    // QAbstractItemDelegate interface
public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // CALENDARYEARDAYDELEGATE_H
