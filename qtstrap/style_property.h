#ifndef QTSTRAP_STYLE_PROPERTY_H
#define QTSTRAP_STYLE_PROPERTY_H

#include <QString>
#include <utility>

namespace qtstrap
{

// experiment
struct border
{
    QString name() const { return "border"; }
};

/**
 * @brief The style_property class
 * Represents property with its components, arguments and values
 */
class style_property
{
public:
    style_property();

private:
    // experiment
    std::pair<QString, QString> m_key_value_pair;

}; // class style_property

} // namespace qtstrap

#endif // STYLE_PROPERTY_H
