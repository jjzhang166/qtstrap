#ifndef QTSTRAP_BASE_WIDGET_STYLE_H
#define QTSTRAP_BASE_WIDGET_STYLE_H

#include "styled_color.h"
#include "properties.h"

namespace qtstrap
{

namespace base
{

/**
 * @brief The widget_style class
 * Each styled control contains a widget_style* member.
 * This class is responsible for providing detailed styling functionality via properties.
 * Styled controls (those derived from styled_widget_base) might have many widget_style's.
 */
class widget_style
{
public:
    widget_style();



private:
    widget_style(const widget_style&);
    widget_style& operator=(const widget_style&);

}; // class widget_style

} // namespace base

} // namespace qtstrap

#endif // QTSTRAP_BASE_WIDGET_STYLE_H
