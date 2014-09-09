#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

// this will be used in koks
namespace qtstrap
{

class main_window : public QMainWindow
{
    Q_OBJECT

public:
    main_window(QWidget *parent = 0);
    ~main_window();
}; // class main_window

} // namespace qtstrap

#endif // MAIN_WINDOW_H
