#ifndef QTSTRAP_BASE_PROPERTIES_H
#define QTSTRAP_BASE_PROPERTIES_H

namespace qtstrap
{

namespace base
{



struct background_color_property : color_property_base
{
    virtual QString name() const
    {
        return style_component::background_color();
    }
};

struct alternate_background_color_property : color_property_base
{
    virtual QString name() const
    {
        return style_component::alternate_background_color();
    }
};

struct border_color_property : color_property_base
{
    virtual QString name() const
    {
        return style_component::border_color();
    }
};

struct border_top_color_property : color_property_base
{
    virtual QString name() const
    {
        return style_component::border_top_color();
    }
};

struct border_left_color_property : color_property_base
{
    virtual QString name() const
    {
        return style_component::border_left_color();
    }
};

struct border_right_color_property : color_property_base
{
    virtual QString name() const
    {
        return style_component::border_right_color();
    }
};

struct border_bottom_color_property : color_property_base
{
    virtual QString name() const
    {
        return style_component::border_bottom_color();
    }
};

struct color_property : color_property_base
{
    virtual QString name() const
    {
        return style_component::color();
    }
};

struct selection_background_color_property : color_property_base
{
    virtual QString name() const
    {
        return style_component::selection_background_color();
    }
};

struct background_property : property_base
{
    virtual QString name() const
    {
        return style_component::background();
    }
};

struct background_image_property : property_base
{
    virtual QString name() const
    {
        return style_component::background_image();
    }
};

struct background_repeat_property : property_base
{
    virtual QString name() const
    {
        return style_component::background_repeat();
    }
};

struct background_position_property : property_base
{
    virtual QString name() const
    {
        return style_component::background_position();
    }
};

struct image_position_property : property_base
{
    virtual QString name() const
    {
        return style_component::image_position();
    }
};

struct subcontrol_position_property : property_base
{
    virtual QString name() const
    {
        return style_component::subcontrol_position();
    }
};

struct text_align_property : property_base
{
    virtual QString name() const
    {
        return style_component::text_align();
    }
};

struct background_attachment_property : property_base
{
    virtual QString name() const
    {
        return style_component::background_attachment();
    }
};

struct dialogbuttonbox_buttons_have_icons_property : property_base
{
    virtual QString name() const
    {
        return style_component::dialogbuttonbox_buttons_have_icons();
    }
};

struct show_decoration_selected_property : property_base
{
    virtual QString name() const
    {
        return style_component::show_decoration_selected();
    }
};

struct background_clip_property : property_base
{
    virtual QString name() const
    {
        return style_component::background_clip();
    }
};

struct background_origin_property : property_base
{
    virtual QString name() const
    {
        return style_component::background_origin();
    }
};

struct subcontrol_origin_property : property_base
{
    virtual QString name() const
    {
        return style_component::subcontrol_origin();
    }
};

struct border_property : property_base
{
    virtual QString name() const
    {
        return style_component::border();
    }
};

struct border_top_property : property_base
{
    virtual QString name() const
    {
        return style_component::border_top();
    }
};

struct border_right_property : property_base
{
    virtual QString name() const
    {
        return style_component::border_right();
    }
};

struct border_bottom_property : property_base
{
    virtual QString name() const
    {
        return style_component::border_bottom();
    }
};

struct border_left_property : property_base
{
    virtual QString name() const
    {
        return style_component::border_left();
    }
};

struct border_color_property : property_base
{
    virtual QString name() const
    {
        return style_component::border_color();
    }
};

struct border_image_property : property_base
{
    virtual QString name() const
    {
        return style_component::border_image();
    }
};

struct border_radius_property : property_base
{
    virtual QString name() const
    {
        return style_component::border_radius();
    }
};

struct border_top_left_radius_property : property_base
{
    virtual QString name() const
    {
        return style_component::border_top_left_radius();
    }
};

struct border_top_right_radius_property : property_base
{
    virtual QString name() const
    {
        return style_component::border_top_right_radius();
    }
};

struct border_bottom_right_radius_property : property_base
{
    virtual QString name() const
    {
        return style_component::border_bottom_right_radius();
    }
};

struct border_bottom_left_radius_property : property_base
{
    virtual QString name() const
    {
        return style_component::border_bottom_left_radius();
    }
};

struct border_style_property : property_base
{
    virtual QString name() const
    {
        return style_component::border_style();
    }
};

struct border_top_style_property : property_base
{
    virtual QString name() const
    {
        return style_component::border_top_style();
    }
};

struct border_right_style_property : property_base
{
    virtual QString name() const
    {
        return style_component::border_right_style();
    }
};

struct border_left_style_property : property_base
{
    virtual QString name() const
    {
        return style_component::border_left_style();
    }
};

struct border_bottom_style_property : property_base
{
    virtual QString name() const
    {
        return style_component::border_bottom_style();
    }
};

struct border_width_property : property_base
{
    virtual QString name() const
    {
        return style_component::border_width();
    }
};

struct margin_property : property_base
{
    virtual QString name() const
    {
        return style_component::margin();
    }
};

struct padding_property : property_base
{
    virtual QString name() const
    {
        return style_component::padding();
    }
};

struct bottom_property : property_base
{
    virtual QString name() const
    {
        return style_component::bottom();
    }
};

struct left_property : property_base
{
    virtual QString name() const
    {
        return style_component::left();
    }
};

struct right_property : property_base
{
    virtual QString name() const
    {
        return style_component::right();
    }
};

struct top_property : property_base
{
    virtual QString name() const
    {
        return style_component::top();
    }
};

struct margin_top_property : property_base
{
    virtual QString name() const
    {
        return style_component::margin_top();
    }
};

struct margin_right_property : property_base
{
    virtual QString name() const
    {
        return style_component::margin_right();
    }
};

struct margin_left_property : property_base
{
    virtual QString name() const
    {
        return style_component::margin_left();
    }
};

struct margin_bottom_property : property_base
{
    virtual QString name() const
    {
        return style_component::margin_bottom();
    }
};

struct max_height_property : property_base
{
    virtual QString name() const
    {
        return style_component::max_height();
    }
};

struct max_width_property : property_base
{
    virtual QString name() const
    {
        return style_component::max_width();
    }
};

struct min_height_property : property_base
{
    virtual QString name() const
    {
        return style_component::min_height();
    }
};

struct min_width_property : property_base
{
    virtual QString name() const
    {
        return style_component::min_width();
    }
};

struct padding_top_property : property_base
{
    virtual QString name() const
    {
        return style_component::padding_top();
    }
};

struct padding_right_property : property_base
{
    virtual QString name() const
    {
        return style_component::padding_right();
    }
};

struct padding_left_property : property_base
{
    virtual QString name() const
    {
        return style_component::padding_left();
    }
};

struct padding_bottom_property : property_base
{
    virtual QString name() const
    {
        return style_component::padding_bottom();
    }
};

struct spacing_property : property_base
{
    virtual QString name() const
    {
        return style_component::spacing();
    }
};

struct width_property : property_base
{
    virtual QString name() const
    {
        return style_component::width();
    }
};

struct button_layout_property : property_base
{
    virtual QString name() const
    {
        return style_component::button_layout();
    }
};

struct height_property : property_base
{
    virtual QString name() const
    {
        return style_component::height();
    }
};

struct icon_size_property : property_base
{
    virtual QString name() const
    {
        return style_component::icon_size();
    }
};

struct lineedit_password_character_property : property_base
{
    virtual QString name() const
    {
        return style_component::lineedit_password_character();
    }
};

struct messagebox_text_interaction_flags_property : property_base
{
    virtual QString name() const
    {
        return style_component::messagebox_text_interaction_flags();
    }
};

struct opacity_property : property_base
{
    virtual QString name() const
    {
        return style_component::opacity();
    }
};

struct font_property : property_base
{
    virtual QString name() const
    {
        return style_component::font();
    }
};

struct font_family_property : property_base
{
    virtual QString name() const
    {
        return style_component::font_family();
    }
};

struct paint_alternating_row_colors_for_empty_area_property : property_base
{
    virtual QString name() const
    {
        return style_component::paint_alternating_row_colors_for_empty_area();
    }
};

struct font_size_property : property_base
{
    virtual QString name() const
    {
        return style_component::font_size();
    }
};

struct font_style_property : property_base
{
    virtual QString name() const
    {
        return style_component::font_style();
    }
};

struct font_weight_property : property_base
{
    virtual QString name() const
    {
        return style_component::font_weight();
    }
};

struct gridline_color_property : property_base
{
    virtual QString name() const
    {
        return style_component::gridline_color();
    }
};

struct image_property : property_base
{
    virtual QString name() const
    {
        return style_component::image();
    }
};

struct position_property : property_base
{
    virtual QString name() const
    {
        return style_component::position();
    }
};

struct text_decoration_property : property_base
{
    virtual QString name() const
    {
        return style_component::text_decoration();
    }
};

} // namespace base

} // namespace qtstrap

#endif // QTSTRAP_BASE_PROPERTIES_H
