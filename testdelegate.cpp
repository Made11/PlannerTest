#include "testdelegate.h"
#include <QPainter>
#include <QApplication>
#include <QPushButton>
TestDelegate::TestDelegate()
{

}


void TestDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
//    QPushButton *b = new QPushButton("test");
    QStyleOptionButton button;
    button.rect = option.rect;
    button.text = "test";
    QApplication::style()->drawControl(QStyle::CE_PushButton, &button, painter);


}

QSize TestDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QStyledItemDelegate::sizeHint(option, index);
}
