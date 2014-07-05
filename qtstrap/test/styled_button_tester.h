#ifndef QTSTRAP_TEST_STYLED_BUTTON_TESTER_H
#define QTSTRAP_TEST_STYLED_BUTTON_TESTER_H

#include "base/styled_color.h"

namespace qtstrap
{

namespace test
{

class styled_button_tester
{
public:
    styled_button_tester();

public:
    static void start_complete_test();

public:
    static void test_default_creation();
    static void test_types();
    static void test_categories();
    static void test_colors();
    static bool test_states();
    static bool test_indicator();
    static bool test_minimum_size_appearance();
    static bool test_maximum_size_appearance();
    static bool test_resizing();
    static bool test_menu();
    static bool test_rounded();

private:
    static void test_colors_private_(base::styled_color::value);

public:
    static void test_click();

private:
    styled_button_tester(const styled_button_tester&);
    styled_button_tester& operator=(const styled_button_tester&);

}; // class styled_button_test

} // namespace test

} // namespace qtstrap

#endif // QTSTRAP_TEST_STYLED_BUTTON_TESTER_H
