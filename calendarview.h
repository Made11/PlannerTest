#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H

#include <QWidget>

namespace Ui {
class CalendarView;
}

class CalendarView : public QWidget
{
    Q_OBJECT

public:
    explicit CalendarView(QWidget *parent = nullptr);
    ~CalendarView();

private:
    Ui::CalendarView *ui;
};

#endif // CALENDARVIEW_H
