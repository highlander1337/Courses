#include "lcd.h"
#include "main.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(PIN_LCD_RS, PIN_LCD_RW, PIN_LCD_EN, PIN_LCD_D4, PIN_LCD_D5, PIN_LCD_D6, PIN_LCD_D7);

void lcd_clear(void)
{
    lcd.clear();
}
void lcd_scroll_left(void)
{
    lcd.scrollDisplayLeft();
}
void lcd_scroll_right(void)
{
    lcd.scrollDisplayRight();
}
void lcd_set_cursor(uint8_t col, uint8_t row)
{
    lcd.setCursor(col, row);
}
void lcd_no_auto_scroll(void)
{
    lcd.noAutoscroll();
}
void lcd_begin(uint8_t cols, uint8_t rows)
{
    lcd.begin(cols, rows);
}
void lcd_move_cursor_R_to_L(void)
{
    lcd.rightToLeft();
}
void lcd_move_cursor_L_to_R(void)
{
    lcd.leftToRight();
}
void lcd_cursor_off(void)
{
    lcd.noCursor();
}
void lcd_cursor_blinkoff(void)
{
    lcd.noBlink();
}
void lcd_print(uint32_t num)
{
    lcd.print(num);
}
void lcd_print(String s)
{
    lcd.print(s);
}
void lcd_print(char c)
{
    lcd.print(c);
}
