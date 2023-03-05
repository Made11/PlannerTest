#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calendaryearmodel.h"
#include "calendaryeardaydelegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //    TestModel *pModel = new TestModel();
    _spModel = QSharedPointer<CalendarYearModel>(new CalendarYearModel());

    _spModel->setCalendarYear(2023);
    _spModel->addEntry("urlaub", QList<QPair<QDate, QDate> >() << qMakePair(QDate(2023,2,1),QDate(2023,2,4)));
    _spModel->addEntry("mobile", QList<QPair<QDate, QDate> >() << qMakePair(QDate(2023,2,15),QDate(2023,3,25)));
    ui->tableView->setModel(_spModel.data());
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
    foreach (QModelIndex miIndex, ui->tableView->selectionModel()->selectedIndexes()) {
        _spModel->addEntry("urlaub", miIndex);
    }

}

