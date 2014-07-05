#ifndef QTSTRAP_STYLED_BUTTON_H
#define QTSTRAP_STYLED_BUTTON_H

#include "base/styled_widget.h"

#include <QPushButton>

namespace qtstrap
{

class styled_button :
        public QPushButton,
        public base::styled_widget
{
    Q_OBJECT
public:
    explicit styled_button(QWidget *parent = 0);

public:
    virtual QString widget_name() const { return "QPushButton"; }

signals:

public slots:

}; // class styled_button

} // namespace qtstrap

#endif // QTSTRAP_STYLED_BUTTON_H
