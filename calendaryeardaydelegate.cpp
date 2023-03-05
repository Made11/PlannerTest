#include "calendaryeardaydelegate.h"
#include "qpainter.h"
#include "calendaryearmodel.h"
#include "qvariant.h"

CalendarYearDayDelegate::CalendarYearDayDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{

}


void CalendarYearDayDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    CalendarYearModel::CellData data = index.data(CalendarYearModel::DateRole).value<CalendarYearModel::CellData>();
    //    QDate day = index.data(CalendarYearModel::DateRole).toDate();
    QDate day = data.day;
    if(data.bValid) {
        //        painter->save();


        if(day.dayOfWeek() == Qt::Saturday || day.dayOfWeek() == Qt::Sunday) {
            painter->fillRect(option.rect,Qt::lightGray);
        }

        if(day == QDate::currentDate()) {
            painter->fillRect(option.rect,Qt::yellow);
        }

        if (option.state & QStyle::State_Selected) {
            painter->fillRect(option.rect, option.palette.highlight());
        }
        QRectF textRect;
        painter->drawText(option.rect,
                          Qt::AlignLeft | Qt::AlignTop,
                          day.toString("d"),
                          &textRect);

        QRectF eventRect(textRect.left(),textRect.bottom(),option.rect.width(),15);

        //        painter->fillRect(textRect,Qt::black);




        if(data.type == "urlaub") {
            QColor color = Qt::blue;
            color.setAlphaF(0.3);
            QBrush brush;
            brush.setStyle(Qt::BDiagPattern);
            brush.setColor(Qt::blue);
            painter->fillRect(eventRect,brush);
            painter->fillRect(eventRect,color);
        } else if(data.type == "mobile") {
            painter->fillRect(eventRect,Qt::yellow);
        }
        //    painter->setRenderHint(QPainter::Antialiasing, true);
        //    painter->setPen(Qt::NoPen);
        //    if (option.state & QStyle::State_Selected)
        //        painter->setBrush(option.palette.highlightedText());
        //    else
        //        painter->restore();

    } else {
        painter->fillRect(option.rect,Qt::gray);
        QStyledItemDelegate::paint(painter,option,index);
    }

}

QSize CalendarYearDayDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSize s = QStyledItemDelegate::sizeHint(option,index);
    s.setHeight(s.height()*2);
    return s;
}
