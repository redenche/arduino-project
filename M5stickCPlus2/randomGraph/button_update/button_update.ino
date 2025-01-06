/**
 * Инициалы Авторов:
 * @file button.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief M5StickCPlus2 Button Test
 * @version 0.1
 * @date 2023-12-09
 *
 *
 * @Hardwares: M5StickCPlus2
 * @Platform Version: Arduino M5Stack Board Manager v2.0.9
 * @Dependent Library:
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5Unified: https://github.com/m5stack/M5Unified
 * M5StickCPlus2: https://github.com/m5stack/M5StickCPlus2
 *      :)
 */

#include "M5StickCPlus2.h"//добавляем библиотеку стика

void setup() {
    auto cfg = M5.config();//конфиг
    StickCP2.begin(cfg);//инициальзация 
    StickCP2.Display.setRotation(1);//угол поворота экрана
    StickCP2.Display.setTextColor(GREEN);//цвет текста
    StickCP2.Display.setTextDatum(middle_center);//расположение текста
    StickCP2.Display.setTextFont(&fonts::Orbitron_Light_24);//шрифт текста
    StickCP2.Display.setTextSize(1);//размер текста
    StickCP2.Display.drawString("Button Test", StickCP2.Display.width() / 2,
                                StickCP2.Display.height() / 2);//Вывод текста
}


void loop() {
    StickCP2.update();//обновить стик(кнопки порты и прочее)
    if (StickCP2.BtnA.wasPressed()) {
      //когда кнопка А нажата
        StickCP2.Speaker.tone(8000, 20);//проиграть звук 8000тоннов 20 милесикунд
        StickCP2.Display.clear();//очистить дисплей
        StickCP2.Display.drawString("A Btn Pressed",
                                    StickCP2.Display.width() / 2,
                                    StickCP2.Display.height() / 2);//написать кнопка А нажата
    }
    if (StickCP2.BtnA.wasReleased()) {
      //когда кнопка А разжата
        StickCP2.Speaker.tone(8000, 20);//проиграть звук 8000тоннов 20 милесикунд
        StickCP2.Display.clear();//очистить дисплей
        StickCP2.Display.drawString("A Btn Released",
                                    StickCP2.Display.width() / 2,
                                    StickCP2.Display.height() / 2);//написать кнопка А разжата
    }
    if (StickCP2.BtnB.wasPressed()) {
      //когда кнопка В нажата
        StickCP2.Speaker.tone(8000, 20);//проиграть звук 8000тоннов 20 милесикунд
        StickCP2.Display.clear();//очистить дисплей
        StickCP2.Display.drawString("B Btn Pressed",
                                    StickCP2.Display.width() / 2,
                                    StickCP2.Display.height() / 2);//написать кнопка В нажата
    }
    if (StickCP2.BtnB.wasReleased()) {
      //когда кнопка В разжата
        StickCP2.Speaker.tone(8000, 20);//проиграть звук 8000тоннов 20 милесикунд
        StickCP2.Display.clear();//очистить дисплей
        StickCP2.Display.drawString("B Btn Released",
                                    StickCP2.Display.width() / 2,
                                    StickCP2.Display.height() / 2);//написать кнопка В разжата
    }

if (M5.BtnPWR.wasPressed()) {//тут почему то в обычном пакете StickCP2 нет кнопки PWR но есть в общей библиотеке M5
      //когда кнопка  PWR нажата
        StickCP2.Speaker.tone(8000, 20);//проиграть звук 8000тоннов 20 милесикунд
        StickCP2.Display.clear();//очистить дисплей
        StickCP2.Display.drawString("PWR Btn Pressed",
                                    StickCP2.Display.width() / 2,
                                    StickCP2.Display.height() / 2);//написать кнопка PWR Нажата
    }


if (M5.BtnPWR.wasReleased()) {
      //когда кнопка  PWR Разжата
        StickCP2.Speaker.tone(8000, 20);//проиграть звук 8000тоннов 20 милесикунд
        StickCP2.Display.clear();//очистить дисплей
        StickCP2.Display.drawString("PWR Btn Released",
                                    StickCP2.Display.width() / 2,
                                    StickCP2.Display.height() / 2);//написать кнопка PWR разжата
    } 
}
