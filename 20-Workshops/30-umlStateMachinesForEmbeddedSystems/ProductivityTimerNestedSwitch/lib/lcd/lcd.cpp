#include "lcd.h"
#include "main.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(PIN_LCD_RS, PIN_LCD_RW, PIN_LCD_EN, PIN_LCD_D4, PIN_LCD_D5, PIN_LCD_D6, PIN_LCD_D7);

void lcd_clear(void)
{
    lcd.clear();
}
void lcd_print_char(char c)
{
    lcd.print(c);
}
void lcd_scroll_left(void)
{
}
void lcd_scroll_right(void)
{
}
void lcd_set_cursor(int r, int c)
{
}
void lcd_no_auto_scroll(void)
{
}
void lcd_begin(void)
{
}
void lcd_move_cursor_R_to_L(void)
{
}
void lcd_move_cursor_L_to_R(void)
{
}
void lcd_cursor_off(void)
{
}
void lcd_cursor_blinkoff(void)
{
}
void lcd_insert_number(int num)
{
}
void lcd_print_string(String s)
{
}
