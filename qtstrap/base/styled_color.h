#ifndef QTSTRAP_BASE_STYLED_COLOR_H
#define QTSTRAP_BASE_STYLED_COLOR_H

#include <QString>

#include "../utility/double_map.h"

namespace qtstrap
{

namespace base
{

struct styled_color
{
    enum value
    {
        UNDEFINED = -1,

        CLOUDS,
        SILVER,
        CONCRETE,
        ASBESTOS,
        ALIZARIN,
        POMEGRANATE,
        PETER_RIVER,
        BELIZE_HOLE,
        WET_ASPHALT,
        MIDNIGHT_BLUE,
        SUN_FLOWER,
        ORANGE,
        CARROT,
        PUMPKIN,
        TURQUOISE,
        GREEN_SEA,
        EMERALD,
        NEPHRITIS,
        AMETHYST,
        WISTERIA,
        WHITE,

        COUNT
    };

    static QString to_string(value )
    {
        // TODO: waiting for double_map
        return "";
    }

}; // struct styled_color

} // namespace base

} // namespace qtstrap

#endif // QTSTRAP_BASE_STYLED_COLOR_H
