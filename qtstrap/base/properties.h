#ifndef QTSTRAP_BASE_PROPERTIES_H
#define QTSTRAP_BASE_PROPERTIES_H

#include <QScopedPointer>

#include "property_types.h"
#include "property_pseudo_states.h"

namespace qtstrap
{

namespace base
{

struct property
{
    property() {  }
    explicit property(property_base_t* pb) { m_type.reset(pb); }
    virtual QString name() const = 0;
    virtual QString suffix() const { return ""; }
    virtual QString value() const
    {
        return name() + style_component::colon() + style_component::whitespace()
                + m_type->value() + suffix() + style_component::semicolon();
    }

    virtual property_base_t* type() { return m_type.data(); }

protected:
    virtual void set_type(property_base_t* t) { Q_ASSERT(0 != t); m_type.reset(t); }

protected:
    QScopedPointer<property_base_t> m_type;

}; // struct property

/// @struct brush_property_base
/// @brief Base class for all brush type properties
struct brush_property_base : virtual property
{
    virtual brush_property_t* type() { return m_type.data(); }
    virtual void set_burhs_type(brush_property_t* t) { set_type(t); }
};

/// @struct alternate_background_color_property
/// @group Brush (@ref brush_property_t)
struct alternate_background_color_property : brush_property_base
{
    virtual QString name() const
    {
        return style_component::alternate_background_color();
    }

}; // struct alternate_background_color_property

/// @struct background_property
/// @group Background (@ref background_property_t)
struct background_property : property
{
    virtual QString name() const
    {
        return style_component::background();
    }

    virtual background_property_t* type() { return m_type.data(); }
    virtual void set_background_type(background_property_t* t) { set_type(t); }

}; // struct background_property

/// @struct background_color_property
/// @group Brush
struct background_color_property : brush_property_base
{
    virtual QString name() const
    {
        return style_component::background_color();
    }

}; // struct background_color_property

/// @struct background_image_property
/// @group Url
struct background_image_property : property
{
    virtual QString name() const
    {
        return style_component::background_image();
    }

    virtual url_property_t* type() { return m_type.data(); }
    virtual void set_url_type(url_property_t* t) { set_type(t); }

}; // struct background_image_property

/// @struct background_repeat_property
/// @group Repeat
struct background_repeat_property : property
{
    virtual QString name() const
    {
        return style_component::background_repeat();
    }

    virtual repeat_property_t* type() { return m_type.data(); }
    virtual void set_repeat_type(repeat_property_t* t) { set_type(t); }

}; // struct background_repeat_property

/// @struct background_position_property
/// @group Alignment
struct background_position_property : property
{
    virtual QString name() const
    {
        return style_component::background_position();
    }

    virtual alignment_property_t* type() { return m_type.data(); }
    virtual void set_alignment_type(alignment_property_t* t) { set_type(t); }

}; // struct background_position_property

/// @struct background_attachment_property
/// @group Attachment
struct background_attachment_property : property
{
    virtual QString name() const
    {
        return style_component::background_attachment();
    }

    virtual attachment_property_t* type() { return m_type.data(); }
    virtual void set_attachment_type(attachment_property_t* t) { set_type(t); }

}; // struct background_attachment_property

/// @struct background_clip_property
/// @group Origin
struct background_clip_property : property
{
    virtual QString name() const
    {
        return style_component::background_clip();
    }

    virtual origin_property_t* type() { return m_type.data(); }
    virtual void set_origin_type(origin_property_t* t) { set_type(t); }

}; // struct background_clip_property

/// @struct background_origin_property
/// @group Origin
struct background_origin_property : property
{
    virtual QString name() const
    {
        return style_component::background_origin();
    }

    virtual origin_property_t* type() { return m_type.data(); }
    virtual void set_origin_type(origin_property_t* t) { set_type(t); }

}; // struct background_origin_property


/// @struct border_property_base The base class for all border type properties
struct border_property_base : virtual property
{
    virtual border_property_t* type() { return m_type.data(); }
    virtual void set_border_type(border_property_t* t) { set_type(t); }

}; // struct border_property_base

/// @struct border_property
/// @group Border
struct border_property : border_property_base
{
    virtual QString name() const
    {
        return style_component::border();
    }

}; // struct border_property

/// @struct border_top_property
/// @group Border
struct border_top_property : border_property_base
{
    virtual QString name() const
    {
        return style_component::border_top();
    }

}; // struct border_top_property

/// @struct border_right_property
/// @group Border
struct border_right_property : border_property_base
{
    virtual QString name() const
    {
        return style_component::border_right();
    }

}; // struct border_right_property

/// @struct border_bottom_property
/// @group Border
struct border_bottom_property : border_property_base
{
    virtual QString name() const
    {
        return style_component::border_bottom();
    }

}; // struct border_bottom_property

/// @struct border_left_property
/// @group Border
struct border_left_property : border_property_base
{
    virtual QString name() const
    {
        return style_component::border_left();
    }

}; // struct border_left_property


/// @struct border_color_property
/// @group Box Colors
struct border_color_property : property
{
    virtual QString name() const
    {
        return style_component::border_color();
    }

    virtual box_colors_property_t* type() { return m_type.data(); }
    virtual void set_box_colors_type(box_colors_property_t* t) { set_type(t); }

}; // struct border_color_property


/// @struct border_top_color_property
/// @group Brush
struct border_top_color_property : brush_property_base
{
    virtual QString name() const
    {
        return style_component::border_top_color();
    }

}; // struct border_top_color_property

/// @struct border_left_color_property
/// @group Brush
struct border_left_color_property : brush_property_base
{
    virtual QString name() const
    {
        return style_component::border_left_color();
    }

}; // struct border_left_color_property

/// @struct border_right_color_property
/// @group Brush
struct border_right_color_property : brush_property_base
{
    virtual QString name() const
    {
        return style_component::border_right_color();
    }

}; // struct border_right_color_property

/// @struct border_bottom_color_property
/// @group Brush
struct border_bottom_color_property : brush_property_base
{
    virtual QString name() const
    {
        return style_component::border_bottom_color();
    }

}; // struct border_bottom_color_property


/// @struct border_image_property
/// @group Border Image
struct border_image_property : property
{
    virtual QString name() const
    {
        return style_component::border_image();
    }

    virtual border_image_property_t* type() { return m_type.data(); }
    virtual void set_border_image_type(border_image_property_t* t) { set_type(t); }

}; // struct border_image_property


/// @struct radius_property_base
/// @brief Base class for all radius type properties
struct radius_property_base : virtual property
{
    virtual radius_property_t* type() { return m_type.data(); }
    virtual void set_radius_type(radius_property_t* t) { set_type(t); }

}; // struct radius_property_base

/// @struct border_radius_property
/// @group Radius
struct border_radius_property : radius_property_base
{
    virtual QString name() const
    {
        return style_component::border_radius();
    }

}; // struct border_radius_property

/// @struct border_top_left_radius_property
/// @group Radius
struct border_top_left_radius_property : radius_property_base
{
    virtual QString name() const
    {
        return style_component::border_top_left_radius();
    }

}; // struct border_top_left_radius_property

/// @struct border_top_right_radius_property
/// @group Radius
struct border_top_right_radius_property : radius_property_base
{
    virtual QString name() const
    {
        return style_component::border_top_right_radius();
    }

}; // struct border_top_right_radius_property

/// @struct border_bottom_right_radius_property
/// @group Radius
struct border_bottom_right_radius_property : radius_property_base
{
    virtual QString name() const
    {
        return style_component::border_bottom_right_radius();
    }

}; // struct border_bottom_right_radius_property

/// @struct border_bottom_left_radius_property
/// @group Radius
struct border_bottom_left_radius_property : radius_property_base
{
    virtual QString name() const
    {
        return style_component::border_bottom_left_radius();
    }

}; // struct border_bottom_left_radius_property


/// @struct border_style_base
/// @brief Base class for all border style type properties
struct border_style_property_base : virtual property
{
    virtual border_style_property_t* type() { return m_type.data(); }
    virtual void set_border_style_type(border_style_property_t* t) { set_type(t); }

}; // struct border_style_property_base

/// @struct border_style_property
/// @group Border Style
struct border_style_property : border_style_property_base
{
    virtual QString name() const
    {
        return style_component::border_style();
    }

}; // struct border_style_property

/// @struct border_top_style_property
/// @group Border Style
struct border_top_style_property : border_style_property_base
{
    virtual QString name() const
    {
        return style_component::border_top_style();
    }

}; // struct border_top_style_property

/// @struct border_right_style_property
/// @group Border Style
struct border_right_style_property : border_style_property_base
{
    virtual QString name() const
    {
        return style_component::border_right_style();
    }

}; // struct border_right_style_property

/// @struct border_left_style_property
/// @group Border Style
struct border_left_style_property : border_style_property_base
{
    virtual QString name() const
    {
        return style_component::border_left_style();
    }

}; // struct border_left_style_property

/// @struct border_bottom_style_property
/// @group Border Style
struct border_bottom_style_property : border_style_property_base
{
    virtual QString name() const
    {
        return style_component::border_bottom_style();
    }

}; // struct border_bottom_style_property


/// @struct border_width_property
/// @group Box Lengths
struct border_width_property : property
{
    virtual QString name() const
    {
        return style_component::border_width();
    }

    virtual box_lengths_property_t* type() { return m_type.data(); }
    virtual void set_box_lengths_type(box_lengths_property_t* t) { set_type(t); }

}; // struct border_width_property


/// @struct length_property_base
/// @group Length
struct length_property_base : virtual property
{
    virtual length_property_t* type() { return m_type.data(); }
    virtual void set_length_type(length_property_t* t) { set_type(t); }

}; // struct length_property_base

/// @struct border_top_width
/// @group Length
struct border_top_width : length_property_base
{
    virtual QString name() const { return style_component::border_top_width(); }
};

/// @struct border_left_width
/// @group Length
struct border_left_width : length_property_base
{
    virtual QString name() const { return style_component::border_left_width(); }
};

/// @struct border_right_width
/// @group Length
struct border_right_width : length_property_base
{
    virtual QString name() const { return style_component::border_right_width(); }
};

/// @struct border_bottom_width
/// @group Length
struct border_bottom_width : length_property_base
{
    virtual QString name() const { return style_component::border_bottom_width(); }
};

// CONTINUE HERE
// FROM: bottom






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





struct subcontrol_origin_property : property_base
{
    virtual QString name() const
    {
        return style_component::subcontrol_origin();
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
