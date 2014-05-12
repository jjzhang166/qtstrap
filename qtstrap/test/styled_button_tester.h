#ifndef QTSTRAP_TEST_STYLED_BUTTON_TESTER_H
#define QTSTRAP_TEST_STYLED_BUTTON_TESTER_H

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
    static void test_states();
    static void test_indicator();
    static void test_minimum_size_appearance();
    static void test_maximum_size_appearance();
    static void test_resizing();
    static void test_menu();
    static void test_rounded();

private:
    static void test_colors_private_(styled_color::color_value);

public:
    static void test_click();

private:
    styled_button_tester(const styled_button_tester&);
    styled_button_tester& operator=(const styled_button_tester&);

}; // class styled_button_test

} // namespace test

} // namespace qtstrap

#endif // QTSTRAP_TEST_STYLED_BUTTON_TESTER_H
