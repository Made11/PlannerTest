#include "calendarview.h"
#include "qgridlayout.h"
#include "ui_calendarview.h"
#include "qlabel.h"

CalendarView::CalendarView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalendarView)
{
    ui->setupUi(this);
    QGridLayout *gl = new QGridLayout(this);

    for (int i = 0; i < 12; ++i) {
        gl->addWidget(new QLabel("test"),0,i);
    }

}

CalendarView::~CalendarView()
{
    delete ui;
}
