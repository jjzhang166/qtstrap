#include "styled_button_test.h"

#include "../styled_button.h"

namespace qtstrap
{

namespace test
{

styled_button_test::styled_button_test()
{
}

void styled_button_test::start_complete_test()
{
    test_default_creation();
    test_categories();
    test_colors();
    test_states();
    test_indicator();
    test_minimum_size_appearance();
    test_maximum_size_appearance();
    test_resizing();
    test_menu();
    test_rounded();
}

void styled_button_test::test_default_creation()
{
    styled_button sb;
    sb.show();
}

void styled_button_test::test_categories()
{
    styled_button sb_cat_default;
    sb_cat_default.set_category(styled_button::CATEGORY_DEFAULT);
    sb_cat_default.show();

    styled_button sb_cat_tile;
    sb_cat_tile.set_category(styled_button::CATEGORY_TILE);
    sb_cat_tile.show();

    styled_button sb_cat_large;
    sb_cat_large.set_category(styled_button::CATEGORY_LARGE);
    sb_cat_large.show();
}

void styled_button_test::test_colors()
{
    return false;
}

bool styled_button_test::test_states()
{
    return false;
}

bool styled_button_test::test_indicator()
{
    return false;
}

bool styled_button_test::test_minimum_size_appearance()
{
    return false;
}

bool styled_button_test::test_maximum_size_appearance()
{
    return false;
}

bool styled_button_test::test_resizing()
{
    return false;
}

bool styled_button_test::test_menu()
{
    return false;
}

bool styled_button_test::test_rounded()
{
    return false;
}

} // namespace test

} // namespace qtstrap
