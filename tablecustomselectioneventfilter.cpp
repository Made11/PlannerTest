#include "tablecustomselectioneventfilter.h"
#include <QEvent>
#include <QTableView>
#include <QMouseEvent>

TableCustomSelectionEventFilter::TableCustomSelectionEventFilter(QTableView *pTableView, QObject *parent)
    : QObject{parent},
      _pTableView(pTableView)
{

}


bool TableCustomSelectionEventFilter::eventFilter(QObject *pWatchedObject, QEvent *pEvent)
{
    if (pEvent->type() == QEvent::MouseButtonPress) {
        QMouseEvent *pMouseEvent = dynamic_cast<QMouseEvent *>(pEvent);
        if (pMouseEvent->modifiers() != Qt::ShiftModifier) {
            _mifirstSelectedIndex = QModelIndex();
        }

        _miIndexOfMousePressedPosition = _pTableView->indexAt(pMouseEvent->pos());
        return true;
    } else if (pEvent->type() == QEvent::MouseButtonRelease) {
        QMouseEvent *pMouseEvent = dynamic_cast<QMouseEvent *>(pEvent);
        if(_miIndexOfMousePressedPosition == _pTableView->indexAt(pMouseEvent->pos())) {
            if (pMouseEvent->modifiers() == Qt::ShiftModifier) {
                QModelIndexList milSelectedIndexes = _pTableView->selectionModel()->selectedIndexes();
                if(!milSelectedIndexes.isEmpty()) {
                    _pTableView->selectionModel()->clearSelection();
                    if(!_mifirstSelectedIndex.isValid()) {
                        _mifirstSelectedIndex = milSelectedIndexes.first();
                    }
                    this->selectCustomStyle(_miIndexOfMousePressedPosition, _mifirstSelectedIndex);

                }

            } else {
                //                if(pMouseEvent->modifiers() != Qt::ControlModifier) {
                //                    _pTableView->selectionModel()->clearSelection();
                //                }
                _pTableView->selectionModel()->clearSelection();
                _pTableView->selectionModel()->select(_miIndexOfMousePressedPosition, QItemSelectionModel::Select);
            }
        }
        return true;
    } else if (pEvent->type() == QEvent::MouseMove) {
        QMouseEvent *pMouseEvent = dynamic_cast<QMouseEvent *>(pEvent);
        const QModelIndex miIndexOfCurrentMousePosition = _pTableView->indexAt(pMouseEvent->pos());
        if(!miIndexOfCurrentMousePosition.isValid()) {
            return true;
        }
        _pTableView->selectionModel()->clearSelection();
        this->selectCustomStyle(miIndexOfCurrentMousePosition, _miIndexOfMousePressedPosition);
        return true;
    }
    else {
        return QObject::eventFilter(pWatchedObject, pEvent);
    }
}

void TableCustomSelectionEventFilter::selectCustomStyle(const QModelIndex &miFromIndex, const QModelIndex &miToIndex)
{
    const QModelIndex miStartIndex = qMin(miFromIndex, miToIndex);
    const QModelIndex miEndIndex = qMax(miFromIndex, miToIndex);

    for (int iRow = miStartIndex.row(); iRow <= miEndIndex.row(); ++iRow) {
        for (int iColumn = (iRow == miStartIndex.row() ? miStartIndex.column() : 0); iColumn <= ((iRow == miStartIndex.row() && iRow == miEndIndex.row()) || iRow == miEndIndex.row() ? miEndIndex.column() : _pTableView->model()->columnCount()); ++iColumn) {
            _pTableView->selectionModel()->select(_pTableView->model()->index(iRow,iColumn), QItemSelectionModel::Select);
        }
    }
}
