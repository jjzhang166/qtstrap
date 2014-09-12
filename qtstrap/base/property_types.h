#ifndef QTSTRAP_BASE_PROPERTY_TYPES_H
#define QTSTRAP_BASE_PROPERTY_TYPES_H

#include <QString>
#include <QLinearGradient>
#include <QConicalGradient>
#include <QRadialGradient>
#include <QSharedPointer>
#include <QUrl>
#include <QVector>

#include "style_components.h"
#include "styled_color.h"


namespace qtstrap
{

namespace base
{


struct property_base_t
{
public:
    property_base_t() {}
    virtual ~property_base_t() {}

public:
    virtual QString value() const = 0;
    virtual QString type_name() const = 0;

private:
    property_base_t(const property_base_t&);
    property_base_t& operator=(const property_base_t&);
};

/// @struct alignment_property_t The Alignment property type
struct alignment_property_t : virtual property_base_t
{
    enum alignment_values
    {
        TOP = 0,
        BOTTOM,
        LEFT,
        RIGHT,
        CENTER
    };

    virtual ~alignment_property_t() {}

public:
    alignment_property_t() : m_alignment(CENTER) {}

public:
    virtual QString type_name() const { return style_component::alignment_type_name(); }
    virtual QString value() const { return m_alignment; }

public:
    void set_alignment(alignment_values v)
    {
        switch (v)
        {
        case TOP:
            m_alignment = style_component::top();
            break;
        case BOTTOM:
            m_alignment = style_component::bottom();
            break;
        case LEFT:
            m_alignment = style_component::left();
            break;
        case RIGHT:
            m_alignment = style_component::right();
            break;
        case CENTER:
            m_alignment = style_component::center();
            break;
        default:
            m_alignment = "";
            break;
        }
    }

private:
    QString m_alignment;

}; // struct alignment_property_t

/// @struct attachment_property_t The Attachment property type
struct attachment_property_t : virtual property_base_t
{
    enum attachment_values
    {
        SCROLL = 0,
        FIXED
    };

    virtual ~attachment_property_t() {}

public:
    virtual QString type_name() const { return style_component::attachment_type_name(); }
    virtual QString value() const { return m_attachment; }

public:
    void set_attachment(attachment_values v)
    {
        switch (v)
        {
        case SCROLL:
            m_attachment = style_component::scroll();
            break;
        case FIXED:
            m_attachment = style_component::fixed();
            break;
        default:
            m_attachment = "";
            break;
        }
    }

private:
    QString m_attachment;

}; // struct attachment_property_t

/// @struct boolean_property_t The Boolean Property, either 1 or 0
struct boolean_property_t : virtual property_base_t
{
    virtual ~boolean_property_t() {}

    virtual QString type_name() const { return style_component::boolean_type_name(); }
    virtual QString value() const { return m_boolean ? "1" : "0"; }

public:
    void set_boolean(bool b) { m_boolean = b; }

private:
    bool m_boolean;
};

/// @struct color_property_t The Color property type, used as 'base' for colorable types
struct color_property_t : virtual property_base_t
{
    virtual ~color_property_t() {}

    virtual QString type_name() const { return style_component::color_type_name(); }
    virtual QString value() const { return m_color; }

public:    
    void set_styled_color(styled_color::value v) { m_color = styled_color::to_string(v); }
    void set_rgba(qint16 r, qint16 g, qint16 b, qint16 a = 0) { m_color = QColor::fromRgb(r, g, b, a).name(); }
    void set_hsva(qint16 h, qint16 s, qint16 v, qint16 a = 0) { m_color = QColor::fromHsv(h, s, v, a).name(); }
    void set_qcolor(const QColor& c) { m_color = c.name(); }

private:
    QString m_color;

}; // struct color_property_t

/// @struct gradient_property_t The Linear, Conical, Radial Gradient property type
struct gradient_property_t : virtual property_base_t
{
    virtual ~gradient_property_t() {}

    virtual QString type_name() const { return style_component::gradient_type_name(); }
    virtual QString value() const { return m_gradient; }

public:
    void set_linear_gradient(const QLinearGradient& lgr)
    {
        QPointF start = lgr.start();
        QPointF final = lgr.finalStop();
        QGradientStops stops = lgr.stops();
        typedef style_component SC;
        m_gradient = SC::qlineargradient() + SC::bracket_open()
                + SC::x1() + SC::colon() + QString::number(start.x()) + SC::comma()
                + SC::y1() + SC::colon() + QString::number(start.y()) + SC::comma()
                + SC::x2() + SC::colon() + QString::number(final.x()) + SC::comma()
                + SC::y2() + SC::colon() + QString::number(final.y())
                ; // the last comma is set by foreach
        foreach (const QGradientStop& item, stops)
        {
            m_gradient += SC::comma() + SC::whitespace()
                    + SC::stop() + SC::colon()
                    + QString::number(item.first) + SC::whitespace()
                    + item.second.name();
        }
        m_gradient += SC::bracket_close();
    }

    void set_conical_gradient(const QConicalGradient& cgr)
    {
        QPointF center = cgr.center();
        qreal angle = cgr.angle();
        QGradientStops stops = cgr.stops();
        typedef style_component SC;
        m_gradient = SC::qconicalgradient() + SC::bracket_open()
                + SC::cx() + SC::colon() + QString::number(center.x()) + SC::comma()
                + SC::cy() + SC::colon() + QString::number(center.y()) + SC::comma()
                + SC::angle() + SC::colon() + QString::number(angle)
                ; // the last comma set by foreach
        foreach (const QGradientStop& item, stops)
        {
            m_gradient += SC::comma() + SC::whitespace()
                    + SC::stop() + SC::colon()
                    + QString::number(item.first) + SC::whitespace()
                    + item.second.name();
        }
        m_gradient += SC::bracket_close();
    }

    void set_radial_gradient(const QRadialGradient& rgr)
    {
        QPointF center = rgr.center();
        qreal center_radius = rgr.centerRadius();
        QPointF focal_point = rgr.focalPoint();
        qreal focal_radius = rgr.focalRadius();
        QGradientStops stops = rgr.stops();
        typedef style_component SC;
        m_gradient = SC::qradialgradient() + SC::bracket_open()
                + SC::cx() + SC::colon() + QString::number(center.x()) + SC::comma()
                + SC::cy() + SC::colon() + QString::number(center.y()) + SC::comma()
                + SC::radius() + SC::colon() + QString::number(center_radius) + SC::comma()
                + SC::fx() + SC::colon() + QString::number(focal_point.x()) + SC::comma()
                + SC::fy() + SC::colon() + QString::number(focal_point.y())
                ; // the last comma set by foreach
        foreach (const QGradientStop& item, stops)
        {
            m_gradient += SC::comma() + SC::whitespace()
                    + SC::stop() + SC::colon()
                    + QString::number(item.first) + SC::whitespace()
                    + item.second.name();
        }
        m_gradient += SC::bracket_close();
    }

private:
    QString m_gradient;
}; // struct gradient_property_t

/// @struct palette_role_property_t The Palette role property
struct palette_role_property_t : virtual property_base_t
{
    enum palette_role_values
    {
        ALTERNATE_BASE = 0,
        BASE,
        BRIGHT_TEXT,
        BUTTON,
        BUTTON_TEXT,
        DARK,
        HIGHLIGHT,
        HIGHLIGHTED_TEXT,
        LIGHT,
        LINK,
        LINK_VISITED,
        MID,
        MIDLIGHT,
        SHADOW,
        TEXT,
        WINDOW,
        WINDOW_TEXT
    };

    virtual ~palette_role_property_t() {}

    virtual QString type_name() const { return style_component::palette_role_type_name(); }
    virtual QString value() const
    {
        typedef style_component SC;
        if (m_palette_role.isEmpty()) { return ""; }
        return SC::palette() + SC::bracket_open() + m_palette_role + SC::bracket_close();
    }

public:
    void set_palette_role(palette_role_values v)
    {
        switch (v)
        {
        case ALTERNATE_BASE: { m_palette_role = style_component::alternate_base(); break; }
        case BASE: { m_palette_role = style_component::base(); break; }
        case BRIGHT_TEXT: { m_palette_role = style_component::bright_text(); break; }
        case BUTTON: { m_palette_role = style_component::button(); break; }
        case BUTTON_TEXT: { m_palette_role = style_component::button_text(); break; }
        case DARK: { m_palette_role = style_component::dark(); break; }
        case HIGHLIGHT: { m_palette_role = style_component::highlight(); break; }
        case HIGHLIGHTED_TEXT: { m_palette_role = style_component::highlighted_text(); break; }
        case LIGHT: { m_palette_role = style_component::light(); break; }
        case LINK: { m_palette_role = style_component::link(); break; }
        case LINK_VISITED: { m_palette_role = style_component::link_visited(); break; }
        case MID: { m_palette_role = style_component::mid(); break; }
        case MIDLIGHT: { m_palette_role = style_component::midlight(); break; }
        case SHADOW: { m_palette_role = style_component::shadow(); break; }
        case TEXT: { m_palette_role = style_component::text(); break; }
        case WINDOW: { m_palette_role = style_component::window(); break; }
        case WINDOW_TEXT: { m_palette_role = style_component::window_text(); break; }
        default: { m_palette_role = ""; break; }
        }
    }

private:
    QString m_palette_role;

}; // struct palette_role_property_t

/// @struct brush_property_t The Brush property, specifies a Color or a Gradient or an entry in the Palette.
struct brush_property_t : color_property_t, gradient_property_t,
        palette_role_property_t
{
    enum brush_type
    {
        COLOR,
        GRADIENT,
        PALETTE_ROLE
    };

    brush_property_t(brush_type t = COLOR)
        : m_type(t)
    {}
    virtual ~brush_property_t() {}

    virtual QString type_name() const { return style_component::brush_type_name(); }
    virtual QString value() const
    {
        switch (m_type) {
        case COLOR:
            return color_property_t::value();
        case GRADIENT:
            return gradient_property_t::value();
        case PALETTE_ROLE:
            return palette_role_property_t::value();
        }
    }

public:
    brush_type get_brush_type() const { return m_type; }
    void set_brush_type(brush_type t) { m_type = t; }

private:
    brush_type m_type;

}; // struct brush_property_t

/// @struct url_property_t The Url Property, value returns in form "url('the-url')"
struct url_property_t : virtual property_base_t
{
    virtual ~url_property_t() {}

    virtual QString type_name() const { return style_component::url_type_name(); }
    virtual QString value() const
    {
        if (m_url.isEmpty()) { return ""; }
        return style_component::url() + style_component::bracket_open()
                + m_url + style_component::bracket_close();
    }

public:
    void set_url(const QString& u) { m_url = u; }
    void set_url(const QUrl& u) { m_url = u.toString(); }

private:
    QString m_url;

}; // struct url_property_t

/// @struct repeat_property_t The Repeat property
struct repeat_property_t : virtual property_base_t
{
    enum repeat_values
    {
        REPEAT_X = 0,
        REPEAT_Y,
        REPEAT,
        NO_REPEAT
    };

    virtual ~repeat_property_t() {}

    virtual QString type_name() const { return style_component::repeat_type_name(); }
    virtual QString value() const { return m_repeat; }

public:
    void set_repeat(repeat_values v)
    {
        switch (v)
        {
        case REPEAT_X: { m_repeat = style_component::repeat_x(); break; }
        case REPEAT_Y: { m_repeat = style_component::repeat_y(); break; }
        case REPEAT: { m_repeat = style_component::repeat(); break; }
        case NO_REPEAT: { m_repeat = style_component::no_repeat(); break; }
        default: { m_repeat = ""; break; }
        }
    }

private:
    QString m_repeat;

}; // struct repeat_property_t

/// @struct background_property_t The Background property.
/// Sequence of Brush, Url, Repeat, Alignment
struct background_property_t :
        brush_property_t,
        url_property_t,
        repeat_property_t,
        alignment_property_t
{
    virtual ~background_property_t() {}

public:
    virtual QString type_name() const { return style_component::background_type_name(); }
    virtual QString value() const
    {
        typedef style_component SC;
        return brush_property_t::value() + SC::whitespace()
                + url_property_t::value() + SC::whitespace()
                + repeat_property_t::value() + SC::whitespace()
                + alignment_property_t::value() + SC::whitespace();
    }

}; // struct background_property_t

/// @struct border_style_property_t The Border Style Property
struct border_style_property_t : virtual property_base_t
{
    enum border_style_values
    {
        DASHED = 0,
        DOT_DASH,
        DOT_DOT_DASH,
        DOTTED,
        DOUBLE,
        GROOVE,
        INSET,
        OUTSET,
        RIDGE,
        SOLID,
        NONE
    };

    virtual ~border_style_property_t() {}

    virtual QString type_name() const { return style_component::border_style_type_name(); }
    virtual QString value() const { return m_border_style; }

public:
    void set_border_style(border_style_values v)
    {
        typedef style_component SC;
        switch (v)
        {
        case DASHED: { m_border_style = SC::dashed(); break; }
        case DOT_DASH: { m_border_style = SC::dot_dash(); break; }
        case DOT_DOT_DASH: { m_border_style = SC::dot_dot_dash(); break; }
        case DOTTED: { m_border_style = SC::dotted(); break; }
        case DOUBLE: { m_border_style = SC::double_bstyle(); break; }
        case GROOVE: { m_border_style = SC::groove(); break; }
        case INSET: { m_border_style = SC::inset(); break; }
        case OUTSET: { m_border_style = SC::outset(); break; }
        case RIDGE: { m_border_style = SC::ridge(); break; }
        case SOLID: { m_border_style = SC::solid(); break; }
        case NONE: { m_border_style = SC::none(); break; }
        default: { m_border_style = ""; break; }
        }
    }

private:
    QString m_border_style;

}; // struct border_style_property_t

/// @struct number_property_t The Number Property
struct number_property_t : virtual property_base_t
{
    virtual ~number_property_t() {}

    virtual QString type_name() const { return style_component::number_type_name(); }
    virtual QString value() const { return m_number; }

public:
    void set_number(qint32 n) { m_number = QString::number(n); }
    void set_number(qreal n) { m_number = QString::number(n); }

private:
    QString m_number;

}; // struct number_property_t

/// @struct length_property_t The Length property
struct length_property_t : number_property_t
{
    enum length_units
    {
        PX = 0,
        PT,
        EM,
        EX
    };

    length_property_t() { set_length_unit(PX); }
    virtual ~length_property_t() {}

    virtual QString type_name() const { return style_component::length_type_name(); }
    virtual QString value() const
    {
        QString number = number_property_t::value();
        if (number.isEmpty()) { return ""; }
        return number + m_length_unit;
    }

public:
    void set_length_unit(length_units u)
    {
        switch (u) {
        case PX:
            m_length_unit = style_component::px();
            break;
        case PT:
            m_length_unit = style_component::pt();
            break;
        case EM:
            m_length_unit = style_component::em();
            break;
        case EX:
            m_length_unit = style_component::ex();
            break;
        default:
            m_length_unit = style_component::px();
            break;
        }
    }

    void set_length(qint32 lg) { set_number(lg); }
    void set_length(qint32 lg, length_units u)
    {
        set_number(lg);
        set_length_unit(u);
    }

private:
    QString m_length_unit;

}; // struct length_property_t

/// @struct border_property_t The Border Property
/// A sequence of Border Style, Length, Brush (shorthand border property).
struct border_property_t :
        border_style_property_t,
        length_property_t,
        brush_property_t
{
    virtual ~border_property_t() {}

public:
    virtual QString type_name() const { return style_component::border_type_name(); }
    virtual QString value() const
    {
        return border_style_property_t::value() + style_component::whitespace()
                + length_property_t::value() + style_component::whitespace()
                + brush_property_t::value();
    }

}; // struct border_property_t

/// @struct border_image_property_t The Border Image Property
struct border_image_property_t
        : url_property_t
{
    border_image_property_t()
        : m_is_repeat(false)
        , m_is_stretch(false)
    {}
    virtual ~border_image_property_t() {}

    virtual QString type_name() const { return style_component::border_image_type_name(); }
    virtual QString value() const
    {
        typedef style_component SC;
        return url_property_t::value() + SC::whitespace()
                + m_numbers + SC::whitespace()
                + (m_is_repeat ? SC::repeat() : "") + SC::whitespace()
                + (m_is_stretch ? SC::stretch() : "");
    }

public:
    void set_numbers(qint32 a, qint32 b = -1, qint32 c = -1, qint32 d = -1)
    {
        m_numbers = QString::number(a) + style_component::whitespace();
        if (-1 != b) { m_numbers += QString::number(b) + style_component::whitespace(); }
        if (-1 != c) { m_numbers += QString::number(c) + style_component::whitespace(); }
        if (-1 != d) { m_numbers += QString::number(d) + style_component::whitespace(); }
    }

    void set_repeat(bool b) { m_is_repeat = b; }
    void set_stretch(bool b) { m_is_stretch = b; }

private:
    QString m_numbers;
    bool m_is_repeat;
    bool m_is_stretch;

}; // struct border_image_property_t

/// @struct box_colors_property_t The Box Colors, Brush{1,4}
struct box_colors_property_t : virtual property_base_t
{
    typedef brush_property_t BPT;
    typedef const BPT CBPT;

    virtual ~box_colors_property_t() {}

    virtual QString type_name() const { return style_component::box_colors_type_name(); }
    virtual QString value() const { return m_brushes; }

public:
    void set_brushes(CBPT& b1, CBPT& b2 = BPT(), CBPT& b3 = BPT(), CBPT& b4 = BPT())
    {
        m_brushes = b1.value() + style_component::whitespace()
                + b2.value() + style_component::whitespace()
                + b3.value() + style_component::whitespace()
                + b4.value() + style_component::whitespace();
    }

private:
    QString m_brushes;

}; // struct box_colors_property_t

/// @struct box_lengths_property_t The Box Lengths, Length{1, 4}
/// Could be a template class with the box_colors_property_t, but currently not worth it
struct box_lengths_property_t : virtual property_base_t
{
    typedef const length_property_t CLPT;

    virtual ~box_lengths_property_t() {}

    virtual QString type_name() const { return style_component::box_lengths_type_name(); }
    virtual QString value() const { return m_lengths; }

public:
    void set_lengths(CLPT& l1, CLPT& l2, CLPT& l3, CLPT& l4)
    {
        m_lengths = l1.value() + style_component::whitespace()
                + l2.value() + style_component::whitespace()
                + l3.value() + style_component::whitespace()
                + l4.value() + style_component::whitespace();
    }

private:
    QString m_lengths;

}; // struct box_lengths_property_t

/// @struct font_size_property_t The Font Size Property ( a Length)
struct font_size_property_t : length_property_t
{
    virtual ~font_size_property_t() {}

    virtual QString type_name() const { return style_component::font_size_type_name(); }
    // value() comes from length_property_t

}; // struct font_size_property_t

/// @struct font_style_property_t The Font Style Property
struct font_style_property_t : virtual property_base_t
{
    enum font_style_values
    {
        NORMAL = 0,
        ITALIC,
        OBLIQUE
    };

    virtual ~font_style_property_t() {}

    virtual QString type_name() const { return style_component::font_style_type_name(); }
    virtual QString value() const { return m_font_style; }

public:
    void set_font_style(font_style_values v)
    {
        switch (v)
        {
        case NORMAL:
            m_font_style = style_component::normal();
            break;
        case ITALIC:
            m_font_style = style_component::italic();
            break;
        case OBLIQUE:
            m_font_style = style_component::oblique();
            break;
        default:
            m_font_style = "";
            break;
        }
    }

private:
    QString m_font_style;

}; // struct font_style_property_t

/// @struct font_weight_property_t The Font Weight Property
struct font_weight_property_t : virtual property_base_t
{
    enum font_weight_values
    {
        NORMAL = -1,
        BOLD = 0,
        _100 = 1,
        _200,
        _300,
        _400,
        _500,
        _600,
        _700,
        _800,
        _900
    };

    virtual ~font_weight_property_t() {}

    virtual QString type_name() const { return style_component::font_weight_type_name(); }
    virtual QString value() const { return m_font_weight; }

public:
    void set_font_weight(font_weight_values v)
    {
        switch (v)
        {
        case NORMAL:
            m_font_weight = style_component::normal();
            break;
        case BOLD:
            m_font_weight = style_component::bold();
            break;
        case _100:
        case _200:
        case _300:
        case _400:
        case _500:
        case _600:
        case _700:
        case _800:
        case _900:
            m_font_weight = QString::number(static_cast<int>(v));
            break;
        default:
            m_font_weight = "";
            break;
        }
    }

private:
    QString m_font_weight;

}; // struct font_weight_property_t

/// @struct font_property_t The Font Property, (Font Style | Font Weight){0,2} Font-Size String
struct font_property_t :
        font_style_property_t,
        font_weight_property_t,
        font_size_property_t
{
    virtual ~font_property_t() {}

    virtual QString type_name() const { return style_component::font_type_name(); }
    virtual QString value() const
    {
        return font_style_property_t::value() + style_component::whitespace()
                + font_weight_property_t::value() + style_component::whitespace()
                + font_size_property_t::value() + style_component::whitespace()
                + m_string;
    }

public:
    void set_string(const QString& s) { m_string = s; }

private:
    QString m_string;

}; // struct font_property_t

/// @struct icon_property_t The Icon Property
/// (Url (icon_mode)? (icon_state)? )*
struct icon_property_t : virtual property_base_t
{
    enum icon_mode
    {
        DISABLED = 1,
        ACTIVE,
        NORMAL,
        SELECTED
    };

    enum icon_state
    {
        ON = 1,
        OFF
    };

    virtual ~icon_property_t() {}

    virtual QString type_name() const { return style_component::icon_type_name(); }
    virtual QString value() const { return m_icon; }

public:
    void clear() { m_icon.clear(); }
    void add_icon(const url_property_t& url)
    {
        if (!m_icon.isEmpty()) { m_icon += style_component::comma(); }
        m_icon += url.value();
    }

    void add_icon(const url_property_t &url, icon_mode m)
    {
        add_icon(url);
        m_icon += style_component::whitespace();
        switch (m)
        {
        case DISABLED: { m_icon += style_component::disabled(); break; }
        case ACTIVE: { m_icon += style_component::active(); break; }
        case NORMAL: { m_icon += style_component::normal(); break; }
        case SELECTED: { m_icon += style_component::selected(); break; }
        }
    }

    void add_icon(const url_property_t &url, icon_mode m, icon_state s)
    {
        add_icon(url, m);
        m_icon += style_component::whitespace();
        m_icon += (ON == s) ? style_component::on() : style_component::off();
    }

private:
    QString m_icon;

}; // struct icon_property_t

/// @struct origin_property_type The Origin Property
struct origin_property_t : virtual property_base_t
{
    enum origin_values
    {
        MARGIN = 1,
        BORDER,
        PADDING,
        CONTENT
    };

    virtual ~origin_property_t() {}

    virtual QString type_name() const { return style_component::origin_type_name(); }
    virtual QString value() const { return m_origin; }

public:
    void set_origin(origin_values v)
    {
        switch (v) {
        case MARGIN:
            m_origin = style_component::margin();
            break;
        case BORDER:
            m_origin = style_component::border();
            break;
        case PADDING:
            m_origin = style_component::padding();
            break;
        case CONTENT:
            m_origin = style_component::content();
            break;
        default:
            m_origin = "";
            break;
        }
    }

private:
    QString m_origin;

}; // struct origin_property_t

struct radius_property_t : virtual property_base_t
{
    virtual ~radius_property_t() {}

    virtual QString type_name() const { return style_component::radius_type_name(); }
    virtual QString value() const { return m_radius; }

public:
    void set_radius(const length_property_t& a, const length_property_t& b)
    {
        m_radius = a.value() + style_component::whitespace() + b.value();
    }

private:
    QString m_radius;
};

} // namespace base

} // namespace qtstrap

#endif // QTSTRAP_BASE_PROPERTY_TYPES_H
