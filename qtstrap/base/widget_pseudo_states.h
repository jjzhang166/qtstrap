#ifndef QTSTRAP_BASE_WIDGET_PSEUDO_STATES_H
#define QTSTRAP_BASE_WIDGET_PSEUDO_STATES_H

#include "style_components.h"
#include "properties.h"

namespace qtstrap
{

namespace base
{

/// @warning OR states are not supported in this release
struct widget_pseudo_state
{
    explicit widget_pseudo_state(bool negated = false)
        : m_is_negated(negated)
    {
    }
    virtual ~widget_pseudo_state() {}

    virtual QString name() const = 0;
    virtual QString value() const
    {
        return style_component::colon() + m_is_negated ? style_component::exclamation_point() : ""
                        + name()
                        + m_and_pseudo_state.isNull() ? "" :  m_and_pseudo_state->value();
    }

    virtual property* property_value() { return m_property.data(); }
    virtual void set_property(property* t) { Q_ASSERT(0 != t); m_property.reset(t); }

    virtual widget_pseudo_state* and_pseudo_state() { return m_and_pseudo_state.data(); }
    virtual void set_and_pseudo_state(widget_pseudo_state* and_state) { m_and_pseudo_state.reset(and_state); }

private:
    QScopedPointer<widget_pseudo_state> m_and_pseudo_state;
    bool m_is_negated;
};

struct active_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_active(); }
};

struct adjoins_item_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_adjoins_item(); }
};

struct alternate_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_alternate(); }
};

struct bottom_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_bottom(); }
};

struct checked_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_checked(); }
};

struct closed_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_closed(); }
};

struct closable_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_closable(); }
};

struct default_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_default(); }
};

struct disabled_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_disabled(); }
};

struct editable_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_editable(); }
};

struct edit_focus_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_edit_focus(); }
};

struct enabled_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_enabled(); }
};

struct exclusive_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_exclusive(); }
};

struct first_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_first(); }
};

struct flat_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_flat(); }
};

struct floatable_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_floatable(); }
};

struct focus_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_focus(); }
};

struct has_children_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_has_children(); }
};

struct has_siblings_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_has_siblings(); }
};

struct horizontal_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_horizontal(); }
};

struct hover_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_hover(); }
};

struct indeterminate_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_indeterminate(); }
};

struct last_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_last(); }
};

struct left_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_left(); }
};

struct maximized_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_maximized(); }
};

struct middle_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_middle(); }
};

struct minimized_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_minimized(); }
};

struct movable_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_movable(); }
};

struct no_frame_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_no_frame(); }
};

struct non_exclusive_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_non_exclusive(); }
};

struct off_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_off(); }
};

struct on_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_on(); }
};

struct only_one_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_only_one(); }
};

struct open_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_open(); }
};

struct next_selected_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_next_selected(); }
};

struct pressed_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_pressed(); }
};

struct previous_selected_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_previous_selected(); }
};

struct read_only_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_read_only(); }
};

struct right_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_right(); }
};

struct selected_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_selected(); }
};

struct top_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_top(); }
};

struct unchecked_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_unchecked(); }
};

struct vertical_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { return style_component::pseudo_state_vertical(); }
};

struct window_pseudo_state : widget_pseudo_state
{
    virtual QString name() const { retrun style_component::window(); }
};

} // namespace base

} // namespace qtstrap

#endif // QTSTRAP_BASE_WIDGET_PSEUDO_STATES_H
