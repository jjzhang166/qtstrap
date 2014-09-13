#include "widget_style.h"

namespace qtstrap
{

namespace base
{

widget_style::widget_style()
{
}

QString widget_style::get_style() const
{
    QString main_properties = widget_name()
            + style_component::brace_open()
            + main_properties_as_string()
            + style_component::brace_close();
    QString pseudo_state_properties;
    //foreach (widget_pseudo_state_ptr, )
    // TODO: continue here!
}

} // namespace base

} // namespace qtstrap
