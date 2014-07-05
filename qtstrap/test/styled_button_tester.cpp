#include "styled_button_tester.h"

#include "../styled_button.h"

namespace qtstrap
{

namespace test
{

styled_button_tester::styled_button_tester()
{
}

void styled_button_tester::start_complete_test()
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

void styled_button_tester::test_default_creation()
{
    styled_button sb;
    sb.show();
}

void styled_button_tester::test_types()
{
    /*
    styled_button sb_type_default;
    sb_type_default.setText("type::default");
    sb_type_default.set_type(styled_button::TYPE_DEFAULT);
    sb_type_default.show();

    styled_button sb_type_tile;
    sb_type_tile.setText("type::tile");
    sb_type_tile.set_type(styled_button::TYPE_TILE);
    sb_type_tile.show();

    styled_button sb_type_large;
    sb_type_large.setText("type::large");
    sb_type_large.set_type(styled_button::TYPE_LARGE);
    sb_type_large.show();
    */
}

void styled_button_tester::test_categories()
{
    /*
    styled_button sb_cat_default;
    sb_cat_default.setText("category::default");
    sb_cat_default.set_category(styled_button::CATEGORY_DEFAULT);
    sb_cat_default.show();

    styled_button sb_cat_danger;
    sb_cat_danger.setText("category::danger");
    sb_cat_danger.set_category(styled_button::CATEGORY_DANGER);
    sb_cat_danger.show();

    styled_button sb_cat_info;
    sb_cat_info.setText("category::info");
    sb_cat_info.set_category(styled_button::CATEGORY_INFO);
    sb_cat_info.show();

    styled_button sb_cat_inverse;
    sb_cat_inverse.setText("category::inverse");
    sb_cat_inverse.set_category(styled_button::CATEGORY_INVERSE);
    sb_cat_inverse.show();

    styled_button sb_cat_warning_light;
    sb_cat_warning_light.setText("category::warning_light");
    sb_cat_warning_light.set_category(styled_button::CATEGORY_WARNING_LIGHT);
    sb_cat_warning_light.show();

    styled_button sb_cat_warning;
    sb_cat_warning.setText("category::warning");
    sb_cat_warning.set_category(styled_button::CATEGORY_WARNING);
    sb_cat_warning.show();

    styled_button sb_cat_primary;
    sb_cat_primary.setText("category::primary");
    sb_cat_primary.set_category(styled_button::CATEGORY_PRIMARY);
    sb_cat_primary.show();

    styled_button sb_cat_success;
    sb_cat_success.setText("category::success");
    sb_cat_primary.set_category(styled_button::CATEGORY_SUCCESS);
    sb_cat_primary.show();

    styled_button sb_cat_highlight;
    sb_cat_highlight.setText("category::highlight");
    sb_cat_highlight.set_category(styled_button::CATEGORY_HIGHLIGHT);
    sb_cat_highlight.show();

    styled_button sb_cat_disabled;
    sb_cat_disabled.setText("category::disabled");
    sb_cat_disabled.set_category(styled_button::CATEGORY_DISABLED);
    sb_cat_disabled.show();
    */
}

void styled_button_tester::test_colors()
{
    /*
    test_colors_private_(styled_color::DEFAULT);
    test_colors_private_(styled_color::CLOUDS);
    test_colors_private_(styled_color::SILVER);
    test_colors_private_(styled_color::CONCRETE);
    test_colors_private_(styled_color::ASBESTOS);
    test_colors_private_(styled_color::ALIZARIN);
    test_colors_private_(styled_color::POMEGRANATE);
    test_colors_private_(styled_color::PETER_RIVER);
    test_colors_private_(styled_color::BELIZE_HOLE);
    test_colors_private_(styled_color::WET_ASPHALT);
    test_colors_private_(styled_color::MIDNIGHT_BLUE);
    test_colors_private_(styled_color::SUN_FLOWER);
    test_colors_private_(styled_color::ORANGE);
    test_colors_private_(styled_color::CARROT);
    test_colors_private_(styled_color::PUMPKIN);
    test_colors_private_(styled_color::TURQUOISE);
    test_colors_private_(styled_color::GREEN_SEA);
    test_colors_private_(styled_color::EMERALD);
    test_colors_private_(styled_color::NEPHRITIS);
    test_colors_private_(styled_color::AMETHYST);
    test_colors_private_(styled_color::WISTERIA);
    test_colors_private_(styled_color::WHITE);
    */
}

void styled_button_tester::test_colors_private_(base::styled_color::value v)
{
    /*
    styled_button sb;
    sb.setText(styled_color::to_string(v));
    sb.set_color(v);
    sb.show();
    */
}

bool styled_button_tester::test_states()
{
    return false;
}

bool styled_button_tester::test_indicator()
{
    return false;
}

bool styled_button_tester::test_minimum_size_appearance()
{
    return false;
}

bool styled_button_tester::test_maximum_size_appearance()
{
    return false;
}

bool styled_button_tester::test_resizing()
{
    return false;
}

bool styled_button_tester::test_menu()
{
    return false;
}

bool styled_button_tester::test_rounded()
{
    return false;
}

} // namespace test

} // namespace qtstrap
