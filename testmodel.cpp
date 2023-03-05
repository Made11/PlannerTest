#include "testmodel.h"

TestModel::TestModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    _mData[qMakePair(2,3)] = RowData("test");
}

int TestModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 10;
}

int TestModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 10;
}

QVariant TestModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if(role == Qt::DisplayRole && _mData.contains(qMakePair(index.row(),index.column()))) {
        return _mData[qMakePair(index.row(),index.column())].sValue;
    }

    return QVariant();
}
