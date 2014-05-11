#ifndef STYLED_BUTTON_TEST_H
#define STYLED_BUTTON_TEST_H

namespace qtstrap
{

namespace test
{

class styled_button_test
{
public:
    styled_button_test();

public:
    static void start_complete_test();

public:
    static void test_default_creation();
    static void test_categories();
    static void test_colors();
    static void test_states();
    static void test_indicator();
    static void test_minimum_size_appearance();
    static void test_maximum_size_appearance();
    static void test_resizing();
    static void test_menu();
    static void test_rounded();

public:
    static bool

private:
    styled_button_test(const styled_button_test&);
    styled_button_test& operator=(const styled_button_test&);

}; // class styled_button_test

} // namespace test

} // namespace qtstrap

#endif // STYLED_BUTTON_TEST_H
