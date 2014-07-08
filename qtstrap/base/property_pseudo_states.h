#ifndef QTSTRAP_BASE_PROPERTY_PSEUDO_STATES_H
#define QTSTRAP_BASE_PROPERTY_PSEUDO_STATES_H

#include "style_components.h"

namespace qtstrap
{

namespace base
{

struct property_pseudo_state
{
    virtual QString name() = 0;
};

struct active_pseudo_state : property_pseudo_state
{
    virtual ~active_pseudo_state() {}

    virtual QString name()
    {
        return style_component::pseudo_state_active();
    }
};

} // namespace base

} // namespace qtstrap

#endif // QTSTRAP_BASE_PROPERTY_PSEUDO_STATES_H
