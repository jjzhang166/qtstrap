#ifndef QTSTRAP_BASE_STYLE_COMPONENTS_H
#define QTSTRAP_BASE_STYLE_COMPONENTS_H

#include <QString>

#include "../utility.h"

namespace qtstrap
{

namespace base
{

class style_component
{
    /// @brief Tokens
public:
    static QString colon() { return ":"; }
    static QString semicolon() { return ";"; }

    /// @brief Properties
public:
    static QString alternate_background_color() { return "alternate-background-color"; }
    static QString background_color() { return "background-color"; }

    static QString border_color() { return "border-color"; }
    static QString border_top_color() { return "border-top-color"; }
    static QString border_left_color() { return "border-left-color"; }
    static QString border_right_color() { return "border-right-color"; }
    static QString border_bottom_color() { return "border-bottom-color"; }

    static QString color() { return "color"; }

    static QString selection_background_color() { return "selection-background-color"; }

    static QString background() { return "background"; }
    static QString background_image() { return "background-image"; }
    static QString background_repeat() { return "background-repeat"; }
    static QString background_position() { return "background-position"; }

    static QString image_position() { return "image-position"; }
    static QString subcontrol_position() { return "subcontrol-position"; }
    static QString text_align() { return "text-align"; }

    static QString background_attachment() { return "background-attachment"; }

    static QString dialogbuttonbox_buttons_have_icons() { return "dialogbuttonbox-buttons-have-icons"; }

    static QString show_decoration_selected() { return "show-decoration-selected"; }

    static QString background_clip() { return "background-clip"; }
    static QString background_origin() { return "background-origin"; }
    static QString subcontrol_origin() { return "subcontrol-origin"; }

    static QString border() { return "border"; }
    static QString border_top() { return "border-top"; }
    static QString border_right() { return "border-right"; }
    static QString border_bottom() { return "border-bottom"; }
    static QString border_left() { return "border-left"; }

    static QString border_color() { return "border-color"; }
    static QString border_image() { return "border-image"; }

    static QString border_radius() { return "border-radius"; }
    static QString border_top_left_radius() { return "border-top-left-radius"; }
    static QString border_top_right_radius() { return "border-top-right-radius"; }
    static QString border_bottom_right_radius() { return "border-bottom-right-radius"; }
    static QString border_bottom_left_radius() { return "border-bottom-left-radius"; }

    static QString border_style() { return "border-style"; }
    static QString border_top_style() { return "border-top-style"; }
    static QString border_right_style() { return "border-right-style"; }
    static QString border_left_style() { return "border-left-style"; }
    static QString border_bottom_style() { return "border-bottom-style"; }

    static QString border_width() { return "border-width"; }
    static QString margin() { return "margin"; }
    static QString padding() { return "padding"; }

    static QString border_top_width() { return "border-top-width"; }
    static QString border_right_width() { return "border-right-width"; }
    static QString border_left_width() { return "border-left-width"; }
    static QString border_bottom_width() { return "border-bottom-width"; }

    static QString bottom() { return "bottom"; }
    static QString left() { return "left"; }
    static QString right() { return "right"; }
    static QString top() { return "top"; }

    static QString margin_top() { return "margin-top"; }
    static QString margin_right() { return "margin-right"; }
    static QString margin_left() { return "margin-left"; }
    static QString margin_bottom() { return "margin-bottom"; }

    static QString max_height() { return "max-height"; }
    static QString max_width() { return "max-width"; }
    static QString min_height() { return "min-height"; }
    static QString min_width() { return "min-width"; }

    static QString padding_top() { return "padding-top"; }
    static QString padding_right() { return "padding-right"; }
    static QString padding_left() { return "padding-left"; }
    static QString padding_bottom() { return "padding-bottom"; }
};

/// @brief base class for all properties
struct property
{    
public:
    virtual QString name() const = 0;
    virtual ~property() {}

public:
    void set_value(const QString& v) { m_value = v; }

    QString value() const { return m_value; }

public:
    QString to_string()
    {
        return name() + style_component::colon()
                + m_value + style_component::semicolon();
    }

private:
    QString m_value;

private:
    property(const property&);
    property& operator=(const property&);
};

struct background_color_property : property
{
    virtual QString name() const
    {
        return style_component::background_color();
    }

public:
    // check this moment
    void set_value(styled_color::color_value v)
    {
        // TODO: convert to string and set
    }
};

struct alternate_background_color_property : property
{
    virtual QString name() const
    {
        return style_component::alternate_background_color();
    }
};

struct border_color_property : property
{
    virtual QString name() const
    {
        return style_component::border_color();
    }
};

struct border_top_color_property : property
{
    virtual QString name() const
    {
        return style_component::border_top_color();
    }
};

struct border_left_color_property : property
{
    virtual QString name() const
    {
        return style_component::border_left_color();
    }
};

struct border_right_color_property : property
{
    virtual QString name() const
    {
        return style_component::border_right_color();
    }
};

struct border_bottom_color_property : property
{
    virtual QString name() const
    {
        return style_component::border_bottom_color();
    }
};

struct color_property : property
{
    virtual QString name() const
    {
        return style_component::color();
    }
};

struct selection_background_color_property : property
{
    virtual QString name() const
    {
        return style_component::selection_background_color();
    }
};

struct background_property : property
{
    virtual QString name() const
    {
        return style_component::background();
    }
};

struct background_image_property : property
{
    virtual QString name() const
    {
        return style_component::background_image();
    }
};

struct background_repeat_property : property
{
    virtual QString name() const
    {
        return style_component::background_repeat();
    }
};

struct background_position_property : property
{
    virtual QString name() const
    {
        return style_component::background_position();
    }
};

struct image_position_property : property
{
    virtual QString name() const
    {
        return style_component::image_position();
    }
};

struct subcontrol_position_property : property
{
    virtual QString name() const
    {
        return style_component::subcontrol_position();
    }
};

struct text_align_property : property
{
    virtual QString name() const
    {
        return style_component::text_align();
    }
};

struct background_attachment_property : property
{
    virtual QString name() const
    {
        return style_component::background_attachment();
    }
};

struct dialogbuttonbox_buttons_have_icons_property : property
{
    virtual QString name() const
    {
        return style_component::dialogbuttonbox_buttons_have_icons();
    }
};

struct show_decoration_selected_property : property
{
    virtual QString name() const
    {
        return style_component::show_decoration_selected();
    }
};

struct background_clip_property : property
{
    virtual QString name() const
    {
        return style_component::background_clip();
    }
};

struct background_origin_property : property
{
    virtual QString name() const
    {
        return style_component::background_origin();
    }
};

struct subcontrol_origin_property : property
{
    virtual QString name() const
    {
        return style_component::subcontrol_origin();
    }
};

struct border_property : property
{
    virtual QString name() const
    {
        return style_component::border();
    }
};

struct border_top_property : property
{
    virtual QString name() const
    {
        return style_component::border_top();
    }
};

struct border_right_property : property
{
    virtual QString name() const
    {
        return style_component::border_right();
    }
};

struct border_bottom_property : property
{
    virtual QString name() const
    {
        return style_component::border_bottom();
    }
};

struct border_left_property : property
{
    virtual QString name() const
    {
        return style_component::border_left();
    }
};

struct border_color_property : property
{
    virtual QString name() const
    {
        return style_component::border_color();
    }
};

struct border_image_property : property
{
    virtual QString name() const
    {
        return style_component::border_image();
    }
};

struct border_radius_property : property
{
    virtual QString name() const
    {
        return style_component::border_radius();
    }
};

struct border_top_left_radius_property : property
{
    virtual QString name() const
    {
        return style_component::border_top_left_radius();
    }
};

struct border_top_right_radius_property : property
{
    virtual QString name() const
    {
        return style_component::border_top_right_radius();
    }
};

struct border_bottom_right_radius_property : property
{
    virtual QString name() const
    {
        return style_component::border_bottom_right_radius();
    }
};

struct border_bottom_left_radius_property : property
{
    virtual QString name() const
    {
        return style_component::border_bottom_left_radius();
    }
};

struct border_style_property : property
{
    virtual QString name() const
    {
        return style_component::border_style();
    }
};

struct border_top_style_property : property
{
    virtual QString name() const
    {
        return style_component::border_top_style();
    }
};

struct border_right_style_property : property
{
    virtual QString name() const
    {
        return style_component::border_right_style();
    }
};

struct border_left_style_property : property
{
    virtual QString name() const
    {
        return style_component::border_left_style();
    }
};

struct border_bottom_style_property : property
{
    virtual QString name() const
    {
        return style_component::border_bottom_style();
    }
};

struct border_width_property : property
{
    virtual QString name() const
    {
        return style_component::border_width();
    }
};

struct margin_property : property
{
    virtual QString name() const
    {
        return style_component::margin();
    }
};

struct padding_property : property
{
    virtual QString name() const
    {
        return style_component::padding();
    }
};

struct bottom_property : property
{
    virtual QString name() const
    {
        return style_component::bottom();
    }
};

struct left_property : property
{
    virtual QString name() const
    {
        return style_component::left();
    }
};

struct right_property : property
{
    virtual QString name() const
    {
        return style_component::right();
    }
};

struct top_property : property
{
    virtual QString name() const
    {
        return style_component::top();
    }
};

struct margin_top_property : property
{
    virtual QString name() const
    {
        return style_component::margin_top();
    }
};

struct margin_right_property : property
{
    virtual QString name() const
    {
        return style_component::margin_right();
    }
};

struct margin_left_property : property
{
    virtual QString name() const
    {
        return style_component::margin_left();
    }
};

struct margin_bottom_property : property
{
    virtual QString name() const
    {
        return style_component::margin_bottom();
    }
};

struct max_height_property : property
{
    virtual QString name() const
    {
        return style_component::max_height();
    }
};

struct max_width_property : property
{
    virtual QString name() const
    {
        return style_component::max_width();
    }
};

struct min_height_property : property
{
    virtual QString name() const
    {
        return style_component::min_height();
    }
};

struct min_width_property : property
{
    virtual QString name() const
    {
        return style_component::min_width();
    }
};

struct padding_top_property : property
{
    virtual QString name() const
    {
        return style_component::padding_top();
    }
};

struct padding_right_property : property
{
    virtual QString name() const
    {
        return style_component::padding_right();
    }
};

struct padding_left_property : property
{
    virtual QString name() const
    {
        return style_component::padding_left();
    }
};

struct padding_bottom_property : property
{
    virtual QString name() const
    {
        return style_component::padding_bottom();
    }
};

} // namespace base

} // namespace qtstrap

#endif // QTSTRAP_BASE_STYLE_COMPONENTS_H
