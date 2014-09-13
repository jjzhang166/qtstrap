#include "widget_style.h"

namespace qtstrap
{

namespace base
{

const QString widget_style::k_default_widget_name = "QWidget";

widget_style::widget_style()
    : m_widget_name(k_default_widget_name)
{
}

QString widget_style::get_style()
{
    QString main_properties = widget_name()
            + style_component::brace_open()
            + main_properties_as_string()
            + style_component::brace_close();

    return main_properties + style_component::whitespace()
            + widget_pseudo_state_properties_as_string() + style_component::whitespace()
            + widget_sub_control_properties_as_string();
}

QString widget_style::widget_name() const
{
    return m_widget_name;
}

void widget_style::set_widget_name(const QString &name)
{
    Q_ASSERT(!name.isEmpty());
    m_widget_name = name;
}

widget_style::property_set widget_style::main_properties()
{
    return m_main_property_set;
}

QString widget_style::main_properties_as_string() const
{
    return get_properties_as_string_(m_main_property_set);
}

void widget_style::set_property(property *p)
{
    Q_ASSERT(0 != p);
    // is this good?
    property_ptr ptr;
    ptr.reset(p);
    m_main_property_set.insert(ptr);
}

widget_style::widget_pseudo_states_map widget_style::widget_pseudo_state_properties()
{
    return m_pseudo_state_properties;
}

QString widget_style::widget_pseudo_state_properties_as_string()
{
    QString pseudo_state_properties;
    for (widget_pseudo_states_map::iterator it = m_pseudo_state_properties.begin();
         it != m_pseudo_state_properties.end(); ++it)
    {
        widget_pseudo_state_ptr state = it->first;
        property_set properties = it->second;
        pseudo_state_properties += widget_name()
                + state->value()
                + style_component::brace_open()
                + get_properties_as_string_(properties)
                + style_component::brace_close() + style_component::whitespace();
    }
    return pseudo_state_properties;
}

void widget_style::set_pseudo_state_property(widget_pseudo_state* ps, property* p)
{
    widget_pseudo_state_ptr state(ps);
    property_ptr prop(p);
    m_pseudo_state_properties[state].insert(prop);
}

widget_style::widget_sub_controls_map widget_style::widget_sub_control_properties()
{
    return m_sub_control_properties;
}

QString widget_style::widget_sub_control_properties_as_string()
{
    QString sub_control_properties;
    for (widget_sub_controls_map::iterator it = m_sub_control_properties.begin();
         it != m_sub_control_properties.end(); ++it)
    {
        widget_sub_control_ptr subctrl = it->first;
        property_set properties = it->second;
        sub_control_properties += widget_name()
                + subctrl->value()
                + style_component::brace_open()
                + get_properties_as_string_(properties)
                + style_component::brace_close() + style_component::whitespace();
    }
    return sub_control_properties;
}

void widget_style::set_sub_control_property(widget_sub_control *sc, property *p)
{
    widget_sub_control_ptr subctrl(sc);
    property_ptr prop(p);
    m_sub_control_properties[subctrl].insert(prop);
}

QString widget_style::get_properties_as_string_(property_set props) const
{
    QString result;
    for (property_set::iterator it = props.begin(); it != props.end(); ++it)
    {
        property* p = it->data();
        Q_ASSERT(0 != p);
        result += p->value();
    }
    return result;
}

} // namespace base

} // namespace qtstrap
