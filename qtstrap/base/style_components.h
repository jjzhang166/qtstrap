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

public:
    static QString alternate_background_color() { return "alternate-background-color"; }
    static QString background_color() { return "background-color"; }

    static QString border_color() { return "border-color"; }
    static QString border_top_color() { return "border-top-color"; }
    static QString border_left_color() { return "border-left-color"; }
    static QString border_right_color() { return "border-right-color"; }
    static QString border_bottom_color() { return "border-bottom-color"; }
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

} // namespace base

} // namespace qtstrap

#endif // QTSTRAP_BASE_STYLE_COMPONENTS_H
