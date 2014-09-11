#ifndef QTSTRAP_BASE_STYLE_COMPONENTS_H
#define QTSTRAP_BASE_STYLE_COMPONENTS_H

#include <QString>

class QColor;

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
    static QString comma() { return ","; }
    static QString parenthesis_open() { return "("; }
    static QString parenthesis_close() { return ")"; }
    static QString bracket_open() { return "["; }
    static QString bracket_close() { return "]"; }
    static QString angle_bracket_open() { return "<"; }
    static QString angle_bracket_close() { return ">"; }
    static QString brace_open() { return "{"; }
    static QString brace_close() { return "}"; }

    static QString whitespace() { return " "; }

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
    static QString selection_color() { return "selection-color"; }

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

    static QString spacing() { return "spacing"; }
    static QString width() { return "width"; }

    static QString button_layout() { return "button-layout"; }
    static QString height() { return "height"; }
    static QString icon_size() { return "icon-size"; }
    static QString lineedit_password_character() { return "lineedit-password-character"; }
    static QString messagebox_text_interaction_flags() { return "messagebox-text-interaction-flags"; }
    static QString opacity() { return "opacity"; }

    static QString font() { return "font"; }
    static QString font_family() { return "font-family"; }
    static QString paint_alternating_row_colors_for_empty_area()
    { return "paint-alternating-row-colors-for-empty-area"; }

    static QString font_size() { return "font-size"; }
    static QString font_style() { return "font-style"; }
    static QString font_weight() { return "font-weight"; }

    static QString gridline_color() { return "gridline-color"; }

    static QString image() { return "image"; }

    static QString position() { return "position"; }
    static QString text_decoration() { return "text-decoration"; }

    static QString center() { return "center"; }

    /// property values
public:
    static QString scroll() { return "scroll"; }
    static QString fixed() { return "fixed"; }

    static QString qlineargradient() { return "qlineargradient"; }
    static QString qradialgradient() { return "qradialgradient"; }
    static QString qconicalgradient() { return "qconicalgradient"; }

    static QString x() { return "x"; }
    static QString y() { return "y"; }
    static QString x1() { return "x1"; }
    static QString y1() { return "y1"; }
    static QString x2() { return "x2"; }
    static QString y2() { return "y2"; }
    static QString x3() { return "x3"; }
    static QString y3() { return "y3"; }
    static QString cx() { return "cx"; }
    static QString cy() { return "cy"; }
    static QString fx() { return "fx"; }
    static QString fy() { return "fy"; }

    static QString radius() { return "radius"; }
    static QString angle() { return "angle"; }
    static QString stop() { return "stop"; }

    static QString palette() { return "palette"; }
    static QString alternate_base() { return "alternate-base"; }
    static QString base() { return "base"; }
    static QString bright_text() { return "bright-text"; }
    static QString button() { return "button"; }
    static QString button_text() { return "button-text"; }
    static QString dark() { return "dark"; }
    static QString highlight() { return "highlight"; }
    static QString highlighted_text() { return "highlighted-text"; }
    static QString light() { return "light"; }
    static QString link() { return "link"; }
    static QString link_visited() { return "link-visited"; }
    static QString mid() { return "mid"; }
    static QString midlight() { return "midlight"; }
    static QString shadow() { return "shadow"; }
    static QString text() { return "text"; }
    static QString window() { return "window"; }
    static QString window_text() { return "window-text"; }

    static QString url() { return "url"; }

    static QString repeat_x() { return "repeat-x"; }
    static QString repeat_y() { return "repeat-y"; }
    static QString repeat() { return "repeat"; }
    static QString no_repeat() { return "no-repeat"; }

    static QString dashed() { return "dashed"; }
    static QString dot_dash() { return "dot-dash"; }
    static QString dot_dot_dash() { return "dot-dot-dash"; }
    static QString dotted() { return "dotted"; }
    static QString double_bstyle() { return "double"; }
    static QString groove() { return "groove"; }
    static QString inset() { return "inset"; }
    static QString outset() { return "outset"; }
    static QString ridge() { return "ridge"; }
    static QString solid() { return "solid"; }
    static QString none() { return "none"; }

    static QString px() { return "px"; }
    static QString pt() { return "pt"; }
    static QString em() { return "em"; }
    static QString ex() { return "ex"; }

    static QString stretch() { return "stretch"; }

    static QString normal() { return "normal"; }
    static QString italic() { return "italic"; }
    static QString oblique() { return "oblique"; }
    static QString bold() { return "bold"; }

    static QString disabled() { return "disabled"; }
    static QString active() { return "active"; }
    static QString selected() { return "selected"; }
    static QString on() { return "on"; }
    static QString off() { return "off"; }

    static QString content() { return "content"; }

    /// property types
public:
    static QString alignment_type_name() { return "Alignment"; }
    static QString attachment_type_name() { return "Attachment"; }
    static QString color_type_name() { return "Color"; }
    static QString gradient_type_name() { return "Gradient"; }
    static QString palette_role_type_name() { return "PaletteRole"; }
    static QString brush_type_name() { return "Brush"; }
    static QString url_type_name() { return "Url"; }
    static QString repeat_type_name() { return "Repeat"; }
    static QString background_type_name() { return "Background"; }
    static QString border_style_type_name() { return "Border Style"; }
    static QString number_type_name() { return "Number"; }
    static QString length_type_name() { return "Length"; }
    static QString border_type_name() { return "Border"; }
    static QString border_image_type_name() { return "Border Image"; }
    static QString box_colors_type_name() { return "Box Colors"; }
    static QString box_lengths_type_name() { return "Box Lengths"; }
    static QString font_size_type_name() { return "Font Size"; }
    static QString font_style_type_name() { return "Font Style"; }
    static QString font_weight_type_name() { return "Font Weight"; }
    static QString font_type_name() { return "Font"; }
    static QString boolean_type_name() { return "Boolean"; }
    static QString icon_type_name() { return "Icon"; }
    static QString origin_type_name() { return "Origin"; }
    static QString radius_type_name() { return "Radius"; }

    /// property pseudo states
public:
    // TODO: think to return ":name" or just "name"
    static QString pseudo_state_active() { return "active"; }

}; // class style_component

} // namespace base

} // namespace qtstrap

#endif // QTSTRAP_BASE_STYLE_COMPONENTS_H
