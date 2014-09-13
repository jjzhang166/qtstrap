#ifndef WIDGET_SUB_CONTROL_H
#define WIDGET_SUB_CONTROL_H

#include "widget_pseudo_states.h"

namespace qtstrap
{

namespace base
{

struct widget_sub_control
{
    widget_sub_control() {}
    virtual ~widget_sub_control() {}

    virtual QString name() const = 0;

    virtual QString value() const
    {
        return style_component::colon() + style_component::colon()
                + name()
                + (m_pseudo_state.isNull() ? "" : m_pseudo_state->value());
    }

    virtual void set_pseudo_state(widget_pseudo_state* s) { Q_ASSERT(0 != s); m_pseudo_state.reset(s); }
    virtual widget_pseudo_state* pseudo_state() { return m_pseudo_state.data(); }

private:
    QScopedPointer<widget_pseudo_state> m_pseudo_state;
}; // struct widget_sub_control

struct add_line_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_add_line(); }
};

struct add_page_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_add_page(); }
};

struct branch_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_branch(); }
};

struct chunk_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_chunk(); }
};

struct close_button_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_close_button(); }
};

struct corner_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_corner(); }
};

struct down_arrow_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_down_arrow(); }
};

struct down_button_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_down_button(); }
};

struct drop_down_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_drop_down(); }
};

struct float_button_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_float_button(); }
};

struct groove_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_groove(); }
};

struct indicator_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_indicator(); }
};

struct handle_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_handle(); }
};

struct icon_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_icon(); }
};

struct item_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_item(); }
};

struct left_arrow_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_left_arrow(); }
};

struct left_corner_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_left_corner(); }
};

struct menu_arrow_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_menu_arrow(); }
};

struct menu_button_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_menu_button(); }
};

struct menu_indicator_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_menu_indicator(); }
};

struct right_arrow_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_right_arrow(); }
};

struct pane_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_pane(); }
};

struct right_corner_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_right_corner(); }
};

struct scroller_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_scroller(); }
};

struct section_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_section(); }
};

struct separator_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_separator(); }
};

struct sub_line_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_sub_line(); }
};

struct sub_page_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_sub_page(); }
};

struct tab_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_tab(); }
};

struct tab_bar_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_tab_bar(); }
};

struct tear_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_tear(); }
};

struct tearoff_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_tearoff(); }
};

struct text_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_text(); }
};

struct title_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_title(); }
};

struct up_arrow_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_up_arrow(); }
};

struct up_button_sub_control : widget_sub_control
{
    virtual QString name() const { return style_component::sub_control_up_button(); }
};

} // namespace base

} // namespace qtstrap

#endif // WIDGET_SUB_CONTROL_H
