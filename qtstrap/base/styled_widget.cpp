#include "styled_widget.h"

namespace qtstrap
{

namespace base
{

styled_widget::styled_widget()
    : m_wgt_style(NULL)
{
}

styled_widget::~styled_widget()
{

}

void styled_widget::set_color(base::styled_color::value v)
{
    // m_wgt_style->set_color
}

void styled_widget::set_color(const QColor &)
{
    // m_wgt_style->set_color
}

void styled_widget::set_color(const QString &)
{
    // m_wgt_style->set_color
}

} // namespace base

} // namespace qtstrap
