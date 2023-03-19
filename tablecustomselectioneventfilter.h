#ifndef TABLECUSTOMSELECTIONEVENTFILTER_H
#define TABLECUSTOMSELECTIONEVENTFILTER_H

#include <QObject>
#include <QModelIndex>
class QTableView;

class TableCustomSelectionEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit TableCustomSelectionEventFilter(QTableView *pTableView, QObject *parent = nullptr);
    bool eventFilter(QObject *pWatchedObject, QEvent *pEvent);

private:
    QTableView *_pTableView;

    QModelIndex _miIndexOfMousePressedPosition;
    QModelIndex _mifirstSelectedIndex;
    void selectCustomStyle(const QModelIndex &miFromIndex,
                           const QModelIndex &miToIndex);
};

#endif // TABLECUSTOMSELECTIONEVENTFILTER_H
