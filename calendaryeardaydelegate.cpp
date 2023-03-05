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
    CalendarYearModel::CellData data = index.data(CalendarYearModel::CellDataRole).value<CalendarYearModel::CellData>();

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


        //        painter->fillRect(textRect,Qt::black);


        if(data.spCalEntry) {
            QRectF eventRect(textRect.left(),textRect.bottom(),option.rect.width(),15);

            if(data.spCalEntry->getFromDate() == day) {
                eventRect.adjust(option.rect.width()*0.20,0,0,0);
            }
            if(data.spCalEntry->getToDate() == day) {
                eventRect.adjust(0,0,-option.rect.width()*0.20,0);
            }
            QColor color = data.spCalEntry->getColor();
            if(data.spCalEntry->isReleased()) {
                QBrush brush;
                brush.setStyle(Qt::BDiagPattern);
                brush.setColor(color);
                painter->fillRect(eventRect,brush);
                color.setAlphaF(0.4);
                painter->fillRect(eventRect,color);
            } else {
                painter->fillRect(eventRect,color);
            }
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
