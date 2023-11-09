#ifndef MAINVIEW_H
#define MAINVIEW_H
#include "Model/headers/main_m.h"
#include "DrawView.h"
#include "Classes/headers/messaggio.h"
#include "search.h"
#include "view_insert_medico.h"
#include "view_insert_infermiere.h"
#include "view_insert_tecnico.h"

#include "insert.h"
#include <QHeaderView>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMainWindow>
#include <QScreen>
#include <QStatusBar>
#include <QLabel>
#include <QIcon>
#include <QPixmap>
#include <QFileDialog>
class MainView : public QMainWindow
{
    Q_OBJECT
private:

    QFileDialog* filedialog_load;
    QFileDialog* filedialog_store;
    Modifica* modifica_model;
    QTableView* table_view;

    QWidget* central;
    QWidget* topFiller;
    QWidget* bottomFiller;

    QMenu* menu_azioni;
    QMenu* menu_file;
    QMenu* menu_help;
    QMenu* menu_delete;
    QMenu* menu_informazioni;

    QAction* load;
    QAction* inserimento;
    QAction* store;
    QAction* cancella;
    QAction* informazioni;
    QAction* help;

    QHBoxLayout* H_layout_1;
    QVBoxLayout* V_layout;

    TableModel* model;

    DrawView* visitor;
    Insert* inserisci_view;
    ViewInsert* insert_view;

    QPixmap* db_status_img;

    QLabel* db_status_text;
    QLabel* db_status;
    QLabel* label_row;
    QLabel* numero_dipendenti;

    QStatusBar* bar;

    Messaggio* show_message;

    int index_saved;

    bool loaded_data;
public:
    explicit MainView(QMainWindow *parent = 0);
    ~MainView() = default;
protected:
    virtual void closeEvent(QCloseEvent *event) override;
private slots:
    void delete_selected_row();
    void aiuto();
    void enable_table();
    void create_choice_view();
    void create_insert_view(const Tipo&);
public slots:
    void onTableClicked(const QModelIndex &);
    void show_specific_info(Persona* const);
    void info_clicked();
    void reset_index();
    void enable_disable_insert();
signals:
    void ask_object_info(u_int);
    void delete_at(u_int);
    void filename(const QString&);
};
#endif // MAINVIEW_H
