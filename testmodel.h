#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QAbstractTableModel>

class TestModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum Column {
        Value, LastColumn
    };


    struct RowData
    {
        RowData(QString sValue = QString()) : sValue(sValue) {}
        QString sValue;
    };
    explicit TestModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QMap<QPair<int,int>, RowData> _mData;

};

#endif // TESTMODEL_H
