#ifndef QTSTRAP_BASE_STYLED_WIDGET_H
#define QTSTRAP_BASE_STYLED_WIDGET_H

#include <QString>
#include <QColor>

#include "widget_style.h"

namespace qtstrap
{

namespace base
{

class styled_widget
{
public:
    styled_widget();
    virtual ~styled_widget();

public:
    virtual QString widget_name() const = 0;

public:
    void set_color(base::styled_color::value v);
    void set_color(const QColor&);
    void set_color(const QString& c);

private:
    QSharedPointer<widget_style> m_wgt_style;

private:
    styled_widget(const styled_widget&);
    styled_widget& operator=(const styled_widget&);

}; // class styled_widget

} // namespace base

} // namespace qtstrap

#endif // QTSTRAP_BASE_STYLED_WIDGET_H
