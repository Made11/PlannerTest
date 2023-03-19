#include "mainwindow.h"
#include "request.h"
#include "ui_mainwindow.h"
#include "calendaryearmodel.h"
#include "calendaryeardaydelegate.h"
#include "requestentry.h"
#include "tablecustomselectioneventfilter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //    TestModel *pModel = new TestModel();
    _spModel = QSharedPointer<CalendarYearModel>(new CalendarYearModel());

    _spModel->setCalendarYear(2023);
    QSharedPointer<Request> spRequest = QSharedPointer<Request>(new Request());
    spRequest->setRequestTimePeriod(qMakePair(QDate(2023,2,1),QDate(2023,2,4)));
    spRequest->setRequestType(Request::Vecation);
//    _spModel->addEntry(spRequest);
//    QSharedPointer<Request> spRequest2 = QSharedPointer<Request>(new Request());
//    spRequest2->setRequestTimePeriod(qMakePair(QDate(2023,3,1),QDate(2023,3,1)));
//    spRequest2->setRequestType(Request::RoomBooking);
//    _spModel->addEntry(spRequest2);


    //    _spModel->addEntry("urlaub", QList<QPair<QDate, QDate> >() << qMakePair(QDate(2023,2,1),QDate(2023,2,4)));
    //    _spModel->addEntry("mobile", QList<QPair<QDate, QDate> >() << qMakePair(QDate(2023,2,15),QDate(2023,3,25)));

    ui->tableView->setModel(_spModel.data());
    ui->tableView->viewport()->installEventFilter(new TableCustomSelectionEventFilter(ui->tableView,ui->tableView));
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->setItemDelegate(new CalendarYearDayDelegate());
    //    ui->tableView->setItemDelegate(new TestDelegate());
    connect(ui->addEntry_pb, SIGNAL(clicked(bool)),this, SLOT(add()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add()
{
//    QSharedPointer<Request> spRequest = QSharedPointer<Request>(new Request());

    QSharedPointer<RequestEntry> spRequest = QSharedPointer<RequestEntry>(new RequestEntry());
    spRequest->setRequestType(Request::Vecation);

    QListIterator<QModelIndex> iterator(ui->tableView->selectionModel()->selectedIndexes());
    QDate fromDate;
    while (iterator.hasNext()) {
        QModelIndex miIndex = iterator.next();
        _spModel->addEntry(spRequest, miIndex);
        QDate curDate = miIndex.data(CalendarYearModel::DateRole).toDate();
        if(!fromDate.isValid()) {
            fromDate = curDate;
        }
        if(iterator.hasNext()) {
            QDate tmpFromDate = iterator.peekNext().data(CalendarYearModel::DateRole).toDate();
            if(tmpFromDate == curDate.addDays(1)) {
                continue;
            }
        }
        spRequest->setRequestTimePeriod(qMakePair(fromDate,
                                                  curDate));
        fromDate = QDate();
    }

    //    foreach (QModelIndex miIndex, ui->tableView->selectionModel()->selectedIndexes()) {
    //        spRequest->setRequestTimePeriod(qMakePair(miIndex.data(CalendarYearModel::DateRole).toDate(),
    //                                                  miIndex.data(CalendarYearModel::DateRole).toDate()));
    //        _spModel->addEntry(spRequest, miIndex);
    //    }

}

