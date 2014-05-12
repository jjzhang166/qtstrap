#include "widget_style_tester.h"

#include "../base/widget_style.h"

namespace qtstrap
{

namespace test
{

widget_style_tester::widget_style_tester()
{
}

void widget_style_tester::start_test()
{

}

void widget_style_tester::test_border_styling()
{
    base::widget_style* ws = new base::widget_style();
    ws->set_property(base::style_component::border(), "1px dotted red");
    ws->add_property(new base::border_property("1px solid black"));
    ws->set_border("1px solid yellow");
    ws->set_property(base::style_component::border_left(), "value");

    // width
    ws->set_property(base::style_component::border_width(), "10px");
    ws->set_property(base::style_component::border_width(), 10);
    ws->set_border_width(10);
    ws->set_border_left_width(5);
    ws->set_property(base::style_component::border_left_width(), 5);
    ws->add_property(new base::border_right_width_property(7));
    base::border_top_width* btw = new base::border_top_width();
    btw->set_value(4);
    ws->set_property(base::style_component::border_top_width(), btw);
    ws->add_property(btw);
}

} // namespace test

} // namespace qtstrap
