#ifndef QTSTRAP_BASE_PROPERTIES_H
#define QTSTRAP_BASE_PROPERTIES_H

#include <QScopedPointer>

#include "property_types.h"

namespace qtstrap
{

namespace base
{

struct property
{
    property() {  }
    virtual ~property() { }
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
    virtual brush_property_t* type() { return dynamic_cast<brush_property_t*>(m_type.data()); }
    virtual void set_brush_type(brush_property_t* t) { set_type(t); }
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

    virtual background_property_t* type() { return dynamic_cast<background_property_t*>(m_type.data()); }
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

    virtual url_property_t* type() { return dynamic_cast<url_property_t*>(m_type.data()); }
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

    virtual repeat_property_t* type() { return dynamic_cast<repeat_property_t*>(m_type.data()); }
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

    virtual alignment_property_t* type() { return dynamic_cast<alignment_property_t*>(m_type.data()); }
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

    virtual attachment_property_t* type() { return dynamic_cast<attachment_property_t*>(m_type.data()); }
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

    virtual origin_property_t* type() { return dynamic_cast<origin_property_t*>(m_type.data()); }
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

    virtual origin_property_t* type() { return dynamic_cast<origin_property_t*>(m_type.data()); }
    virtual void set_origin_type(origin_property_t* t) { set_type(t); }

}; // struct background_origin_property


/// @struct border_property_base The base class for all border type properties
struct border_property_base : virtual property
{
    virtual border_property_t* type() { return dynamic_cast<border_property_t*>(m_type.data()); }
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

    virtual box_colors_property_t* type() { return dynamic_cast<box_colors_property_t*>(m_type.data()); }
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

    virtual border_image_property_t* type() { return dynamic_cast<border_image_property_t*>(m_type.data()); }
    virtual void set_border_image_type(border_image_property_t* t) { set_type(t); }

}; // struct border_image_property


/// @struct radius_property_base
/// @brief Base class for all radius type properties
struct radius_property_base : virtual property
{
    virtual radius_property_t* type() { return dynamic_cast<radius_property_t*>(m_type.data()); }
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
    virtual border_style_property_t* type() { return dynamic_cast<border_style_property_t*>(m_type.data()); }
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

    virtual box_lengths_property_t* type() { return dynamic_cast<box_lengths_property_t*>(m_type.data()); }
    virtual void set_box_lengths_type(box_lengths_property_t* t) { set_type(t); }

}; // struct border_width_property


/// @struct length_property_base
/// @group Length
struct length_property_base : virtual property
{
    virtual length_property_t* type() { return dynamic_cast<length_property_t*>(m_type.data()); }
    virtual void set_length_type(length_property_t* t) { set_type(t); }

}; // struct length_property_base

struct number_property_base : virtual property
{
    virtual number_property_t* type() { return dynamic_cast<number_property_t*>(m_type.data()); }
    virtual void set_number_type(number_property_t* t) { set_type(t); }
};

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

/// @struct bottom
/// @group Length
struct bottom_property : length_property_base
{
    virtual QString name() const { return style_component::bottom(); }
};

/// @struct button_layout
/// @group Number (@ref number_property_t)
struct button_layout : number_property_base
{
    virtual QString name() const { return style_component::button_layout(); }
};

/// @struct color
/// @group Brush (@ref brush_property_t)
struct color : brush_property_base
{
    virtual QString name() const { return style_component::color(); }
};

/// @struct dialogbuttonbox_buttons_have_icons
/// @group Boolean (@ref boolean_property_t)
struct dialogbuttonbox_buttons_have_icons : property
{
    virtual QString name() const { return style_component::dialogbuttonbox_buttons_have_icons(); }

    virtual boolean_property_t* type() { return dynamic_cast<boolean_property_t*>(m_type.data()); }
    virtual void set_boolean_type(boolean_property_t* t) { set_type(t); }
};

/// @struct font
/// @group Font (@ref font_property_t)
struct font : property
{
    virtual QString name() const { return style_component::font(); }

    virtual font_property_t* type() { return dynamic_cast<font_property_t*>(m_type.data()); }
    void set_font_type(font_property_t* t) { set_type(t); }
};

/// @struct font_family
/// @group Font
/// @note This property's type is plain string
struct font_family : property
{
    virtual QString name() const { return style_component::font_family(); }

    virtual QString string_type() { return m_string_type; }
    virtual void set_string_type(const QString& str) { m_string_type = str; }

private:
    QString m_string_type;
};

/// @struct font_size
/// @group Font
struct font_size : property
{
    virtual QString name() const { return style_component::font_size(); }

    virtual font_size_property_t* type() { return dynamic_cast<font_size_property_t*>(m_type.data()); }
    virtual void set_font_size_type(font_size_property_t* t) { set_type(t); }
};

/// @struct font_style
/// @group Font
struct font_style : property
{
    virtual QString name() const { return style_component::font_style(); }

    virtual font_style_property_t* type() { return dynamic_cast<font_style_property_t*>(m_type.data()); }
    virtual void set_font_style_type(font_style_property_t* t) { set_type(t); }
};

/// @struct font_weight
/// @group Font
struct font_weight : property
{
    virtual QString name() const { return style_component::font_weight(); }

    virtual font_weight_property_t* type() { return dynamic_cast<font_weight_property_t*>(m_type.data()); }
    virtual void set_font_weight_type(font_weight_property_t* t) { set_type(t); }
};

/// @struct gridline_color
/// @group Color
struct gridline_color : property
{
    virtual QString name() const { return style_component::gridline_color(); }

    virtual color_property_t* type() { return dynamic_cast<color_property_t*>(m_type.data()); }
    virtual void set_color_type(color_property_t* t) { set_type(t); }
};

/// @struct height
/// @group Length
struct height : length_property_base
{
    virtual QString name() const { return style_component::height(); }
};

/// @struct icon_size
/// @group Length
struct icon_size : length_property_base
{
    virtual QString name() const { return style_component::icon_size(); }
};

/// @struct image
/// @group Url
/// @note image has type Url+ meaning that accepts a list of Urls, current implementation accepts one Url
struct image : property
{
    virtual QString name() const { return style_component::image(); }

    virtual url_property_t* type() { return dynamic_cast<url_property_t*>(m_type.data()); }
    virtual void set_url_type(url_property_t* t) { set_type(t); }
};

/// @struct image_position
/// @group Alignment
struct image_position : property
{
    virtual QString name() const { return style_component::image_position(); }

    virtual alignment_property_t* type() { return dynamic_cast<alignment_property_t*>(m_type.data()); }
    virtual void set_alignment_type(alignment_property_t* t) { set_type(t); }
};

/// @struct left
/// @Group Length
struct left : length_property_base
{
    virtual QString name() const { return style_component::left(); }
};

/// @lineedit_password_character
/// @group Number
/// @brief The QLineEdit password character as a Unicode number.
/// If this property is not specified, it defaults to the value specified by the current style for the SH_LineEdit_PasswordCharacter style hint.
struct lineedit_password_character : number_property_base
{
    virtual QString name() const { return style_component::lineedit_password_character(); }
};

/// Margins
/// @{
///
/// @struct margin
/// @group Box Lengths
struct margin : property
{
    virtual QString name() const { return style_component::margin(); }

    virtual box_lengths_property_t* type() { return dynamic_cast<box_lengths_property_t*>(m_type.data()); }
    virtual void set_box_lengths_type(box_lengths_property_t* t) { set_type(t); }
};

struct margin_top : length_property_base
{
    virtual QString name() const { return style_component::margin_top(); }
};

struct margin_right : length_property_base
{
    virtual QString name() const { return style_component::margin_right(); }
};

struct margin_bottom : length_property_base
{
    virtual QString name() const { return style_component::margin_bottom(); }
};

struct margin_left : length_property_base
{
    virtual QString name() const { return style_component::margin_left(); }
};

/// @}

/// Max/min length properties
/// @{
///
/// @struct max_height
/// @group Length
struct max_height : length_property_base
{
    virtual QString name() const { return style_component::max_height(); }
};

struct max_width : length_property_base
{
    virtual QString name() const { return style_component::max_width(); }
};

struct min_height : length_property_base
{
    virtual QString name() const { return style_component::min_height(); }
};

struct min_width : length_property_base
{
    virtual QString name() const { return style_component::min_width(); }
};

/// @}

/// @struct messagebox_text_interaction_flags
/// @group Number
struct messagebox_text_interaction_flags : number_property_base
{
    virtual QString name() const { return style_component::messagebox_text_interaction_flags(); }
};

/// @struct opacity
/// @group Number
struct opacity : number_property_base
{
    virtual QString name() const { return style_component::opacity(); }
};

/// @name Padding
/// @{
///
/// @struct padding
/// @group Box Lengths
struct padding : property
{
    virtual QString name() const { return style_component::padding(); }

    virtual box_lengths_property_t* type() { return dynamic_cast<box_lengths_property_t*>(m_type.data()); }
    virtual void set_box_lengths_type(box_lengths_property_t* t) { set_type(t); }
};

struct padding_top : length_property_base
{
    virtual QString name() const { return style_component::padding_top(); }
};

struct padding_right : length_property_base
{
    virtual QString name() const { return style_component::padding_right(); }
};

struct padding_bottom : length_property_base
{
    virtual QString name() const { return style_component::padding_bottom(); }
};

struct padding_left : length_property_base
{
    virtual QString name() const { return style_component::padding_left(); }
};

/// @}

/// @struct paint_alternating_row_colors_for_empty_area
/// @group Boolean
struct paint_alternating_row_colors_for_empty_area : property
{
    virtual QString name() const { return style_component::paint_alternating_row_colors_for_empty_area(); }

    virtual boolean_property_t* type() { return dynamic_cast<boolean_property_t*>(m_type.data()); }
    virtual void set_boolean_type(boolean_property_t* t) { set_type(t); }
};

/// @struct right
/// @group Length
struct right : length_property_base
{
    virtual QString name() const { return style_component::right(); }
};

/// @struct selection_background_color
/// @group Brush
struct selection_background_color : brush_property_base
{
    virtual QString name() const { return style_component::selection_background_color(); }
};

/// @struct selection_color
/// @group Brush
struct selection_color : brush_property_base
{
    virtual QString name() const { return style_component::selection_color(); }
};

/// @struct show_decoration_selected
/// @group Boolean
struct show_decoration_selected : property
{
    virtual QString name() const { return style_component::show_decoration_selected(); }

    virtual boolean_property_t* type() { return dynamic_cast<boolean_property_t*>(m_type.data()); }
    virtual void set_boolean_type(boolean_property_t* t) { set_type(t); }
};

/// @struct spacing
/// @group Length
struct spacing : length_property_base
{
    virtual QString name() const { return style_component::spacing(); }
};

/// @struct subcontrol_origin
/// @group Origin (@ref origin_property_t)
struct subcontrol_origin : property
{
    virtual QString name() const { return style_component::subcontrol_origin(); }

    virtual origin_property_t* type() { return dynamic_cast<origin_property_t*>(m_type.data()); }
    virtual void set_origin_type(origin_property_t* t) { set_type(t); }
};

/// @struct subcontrol_position
/// @group Alignment
struct subcontrol_position : property
{
    virtual QString name() const { return style_component::subcontrol_position(); }

    virtual alignment_property_t* type() { return dynamic_cast<alignment_property_t*>(m_type.data()); }
    virtual void set_alignment_type(alignment_property_t* t) { set_type(t); }
};

/// @struct text_align
/// @group Alignment
struct text_align : property
{
    virtual QString name() const { return style_component::text_align(); }

    virtual alignment_property_t* type() { return dynamic_cast<alignment_property_t*>(m_type.data()); }
    virtual void set_alignment_type(alignment_property_t* t) { set_type(t); }
};

/// @struct text_decoration
/// @group None
/// @note This property holds direct values, so using a separate enum for this
struct text_decoration : property
{
    enum value
    {
        NONE = 0,
        UNDERLINE,
        OVERLINE,
        LINE_THROUGH,

        value_max
    };

    virtual QString name() const { return style_component::text_decoration(); }

    virtual value decoration_type() { return m_decoration; }
    virtual void set_decoration_type(value v) { m_decoration = v; }

private:
    value m_decoration;
};

/// @struct top
/// @group Length
struct top : length_property_base
{
    virtual QString name() const { return style_component::top(); }
};

/// @struct width
/// @group Length
struct width : length_property_base
{
    virtual QString name() const { return style_component::width(); }
};

// CONTINUE HERE
// FROM:






} // namespace base

} // namespace qtstrap

#endif // QTSTRAP_BASE_PROPERTIES_H
