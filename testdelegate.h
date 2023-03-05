#ifndef TESTDELEGATE_H
#define TESTDELEGATE_H

#include <QStyledItemDelegate>

class TestDelegate : public QStyledItemDelegate
{
public:
    TestDelegate();

    // QAbstractItemDelegate interface
public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // TESTDELEGATE_H
