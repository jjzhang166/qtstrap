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
    color_property* color = new color_property();
    brush_property_t* brush_type = new brush_property_t();
    brush_type->set_styled_color(v);
    color->set_brush_type(brush_type);
    m_wgt_style->set_property(color);
}

void styled_widget::set_color(const QColor& qcolor)
{
    color_property* color = new color_property();
    brush_property_t* brush_type = new brush_property_t();
    brush_type->set_qcolor(qcolor);
    color->set_brush_type(brush_type);
    m_wgt_style->set_property(color);
}

void styled_widget::set_color(const QString &)
{
    // m_wgt_style->set_color
}

} // namespace base

} // namespace qtstrap
