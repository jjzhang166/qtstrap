#ifndef QTSTRAP_BASE_WIDGET_STYLE_H
#define QTSTRAP_BASE_WIDGET_STYLE_H

#include <set>
#include <map>

#include "widget_pseudo_states.h"
#include "widget_sub_control.h"

namespace qtstrap
{

namespace base
{

/**
 * @brief The widget_style class
 * Each styled control contains a widget_style* member.
 * This class is responsible for providing detailed styling functionality via properties.
 * Styled controls (those derived from styled_widget_base) might have many widget_style's.
 */
class widget_style
{
public:
    typedef QSharedPointer<property> property_ptr;
    typedef std::set<property_ptr> property_set;
    typedef QSharedPointer<widget_pseudo_state> widget_pseudo_state_ptr;
    typedef std::map<widget_pseudo_state_ptr, property_set> widget_pseudo_states_map;
    typedef QSharedPointer<widget_sub_control> widget_sub_control_ptr;
    typedef std::map<widget_sub_control_ptr, property_set> widget_sub_controls_map;

    widget_style();

    QString get_style() const;

    void set_widget_name(const QString& name);
    QString widget_name() const;

    property_set main_properties();
    QString main_properties_as_string() const;
    void set_property(property* p);

    widget_pseudo_states_map widget_pseudo_state_properties();
    QString widget_pseudo_state_properties_as_string() const;
    void set_pseudo_state_property(widget_pseudo_state* ps, property* p);

    widget_sub_controls_map widget_sub_control_properties();
    QString widget_sub_control_properties_as_string() const;
    void set_sub_control_property(widget_sub_control* sc, property* p);

private:
    QString m_widget_name;
    property_set m_main_property_set;
    widget_pseudo_states_map m_pseudo_state_properties;
    widget_sub_controls_map m_sub_control_properties;

private:
    widget_style(const widget_style&);
    widget_style& operator=(const widget_style&);

}; // class widget_style

} // namespace base

} // namespace qtstrap

#endif // QTSTRAP_BASE_WIDGET_STYLE_H
