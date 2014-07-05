#ifndef QTSTRAP_BASE_PROPERTY_TYPES_H
#define QTSTRAP_BASE_PROPERTY_TYPES_H

#include <QString>
#include <QLinearGradient>
#include <QConicalGradient>
#include <QRadialGradient>
#include <QSharedPointer>

#include "style_components.h"
#include "styled_color.h"


namespace qtstrap
{

namespace base
{


struct property_base_t
{
public:
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
    enum value
    {
        TOP = 0,
        BOTTOM,
        LEFT,
        RIGHT,
        CENTER
    };

public:
    alignment_property_t() : m_alignment(CENTER) {}

public:
    virtual QString type_name() const { return style_component::alignment_type_name(); }

    void set_alignment(value v) { m_alignment = v; }
    virtual QString value() const
    {
        switch (m_alignment)
        {
        case TOP:
            return style_component::top();
        case BOTTOM:
            return style_component::bottom();
        case LEFT:
            return style_component::left();
        case RIGHT:
            return style_component::right();
        case CENTER:
            return style_component::center();
        }
        return "";
    }

private:
    value m_alignment;

}; // struct alignment_property_t

/// @struct attachment_property_t The Attachment property type
struct attachment_property_t : virtual property_base_t
{
    enum value
    {
        SCROLL = 0,
        FIXED
    };

public:
    attachment_property_t() : m_attachment(SCROLL) {}

public:
    virtual QString type_name() const { return style_component::attachment_type_name(); }

    void set_attachment(value v) { m_attachment = v; }
    virtual QString value() const
    {
        switch (m_attachment)
        {
        case SCROLL:
            return style_component::scroll();
        case FIXED:
            return style_component::fixed();
        }
        return "";
    }

private:
    value m_attachment;

}; // struct attachment_property_t

/// @struct color_property_t The Color property type, used as 'base' for colorable types
struct color_property_t : virtual property_base_t
{
    void set_styled_color(styled_color::value v) { m_color = styled_color::to_string(v); }
    void set_rgba(qint16 r, qint16 g, qint16 b, qint16 a = 0) { m_color = QColor::fromRgb(r, g, b, a).name(); }
    void set_hsva(qint16 h, qint16 s, qint16 v, qint16 a = 0) { m_color = QColor::fromHsv(h, s, v, a).name(); }
    void set_qcolor(const QColor& c) { m_color = c.name(); }

public:
    virtual QString type_name() const { return style_component::color_type_name(); }
    virtual QString value() const { return m_color; }

private:
    QString m_color;

}; // struct color_property_t

/// @struct gradient_property_t The Linear, Conical, Radial Gradient property type
struct gradient_property_t : virtual property_base_t
{
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
        foreach (const QPair<qreal, QColor>& item, stops)
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
        foreach (const QPair<qreal, QColor>& item, stops)
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
        foreach (const QPair<qreal, QColor>& item, items)
        {
            m_gradient += SC::comma() + SC::whitespace()
                    + SC::stop() + SC::colon()
                    + QString::number(item.first) + SC::whitespace()
                    + item.second.name();
        }
        m_gradient += SC::bracket_close();
    }

    virtual QString type_name() const { return style_component::gradient_type_name(); }
    virtual QString value() const { return m_gradient; }

private:
    QString m_gradient;
}; // struct gradient_property_t

// CONTINUE HERE
struct palette_role_property_t : virtual property_base_t
{
    enum value
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

    void set_palette_role(value v);

}; // struct palette_role_property_t

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
    {
        m_type = t;
    }

    current_type brush_type() const { return m_type; }
    void set_brush_type(brush_type t) { m_type = t; }

private:
    brush_type m_type;

}; // struct brush_property_t

struct url_property_t : virtual property_base_t
{
    void set_url(const QString& u);
    void set_url(const QUrl& u);

}; // struct url_property_t

struct repeat_property_t : virtual property_base_t
{
    enum value
    {
        REPEAT_X = 0,
        REPEAT_Y,
        REPEAT,
        NO_REPEAT
    };

    void set_repeat(value v);

}; // struct repeat_property_t

struct background_property_t : virtual property_base_t
{
public:
    void set_brush(brush_property_t);
    void set_url(url_property_t);
    void set_repeat(repeat_property_t);
    void set_alignment(alignment_property_t);

public:
    virtual QString value() const;

private:
    brush_property_t m_brush;
    url_property_t m_url;
    repeat_property_t m_repeat;
    alignment_property_t m_alignment;

}; // struct background_property_t

struct border_style_property_t : virtual property_base_t
{
    enum values
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

    void set_border_style(values v);

}; // struct border_style_property_t

struct number_property_t : virtual property_base_t
{
    void set_number(qint32 n);

}; // struct number_property_t

// very sorry for this
struct length_property_t : number_property_t
{
    enum units
    {
        PX = 0,
        PT,
        EM,
        EX
    };

    set_number(qint32, units u = PX);
    set_length(qint32, units);

}; // struct length_property_t

struct border_property_t : border_style_property_t, length_property_t,
        brush_property_t
{
    // sequence of parents

}; // struct border_property_t

struct border_image_property_t : virtual property_base_t
{
    // TODO: don't understand this
/*
    none
    | Url Number{4}

    (stretch | repeat){0,2}
*/

}; // struct border_image_property_t



// TODO: To be continued..

} // namespace base

} // namespace qtstrap

#endif // QTSTRAP_BASE_PROPERTY_TYPES_H
