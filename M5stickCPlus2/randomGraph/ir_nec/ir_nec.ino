/**
.
⠄⠄⠄⠸⣿⡛⠷⣦
⢀⣄⠄⠄⠈⠻⣦⡀⢙⣤
⢸⡟⢷⣄⠄⠄⣨⡷⠄⢻⡇
⠘⣷⡀⠙⠷⠾⠋⠄⠄⠺⣧⣀⣴⠶⢶⡄
 ⠈⠻⢶⣤⣤⣤⣄⣀⣀⣼⠟⠁⠄⢠⣿⠶⣦⡀
       ⠈⢩⡿⠋⠙⠛⠷⣦⣴⣟⠁⠄⣸⣧⣤⣄
      ⣰⡟⠁⠄⠄⠄⠄⠄⠉⠛⢷⣾⠋⠄⠄⣿⣤⣄⡀
     ⣼⠏⠄⠄⠄⣠⡶⠶⣶⣤⣤⣾⡃⠄⣠⡾⠋⠄⢙⣷
     ⢿⡄⠄⠄⠄⠉⠁⠄⠈⠻⣿⣌⠻⢿⣿⠄⠄⣠⣾⡇
     ⠈⢿⣆⠄⠄⠄⠄⠄⠄⠄⠈⠻⣷⡀⠻⠷⠾⢿⣼⣧
        ⠙⣷⠄⠄⠄⠄⠄⠄⠄⠄⠈⠻⣧⡀⠄⠄⠙⠛⠛⠛⠷⣦⡀
          ⢿⣄⠄⠄⠄⠄⠄⠄⠄⠄⠈⢻⣦⠄⠄⣠⡶⢷⣄⠈⢿⡄
           ⠹⣧⠄⠄⠄⠄⠄⠄⠄⠄⢸⣿⠄⢼⡋⠄⠄⠙⢷⣼⡇
            ⢹⡇⠄⠄⠄⠄⠄⠄⠄⠄⢻⣆⠈⠻⣦⡀⠄⠄⠙⠃
            ⢸⡇⠄⠄⠄⠄⠄⠄⠄⠄⢸⡟⠻⣶⣬⣿⡆
           ⢠⡾⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⣧⡀
           ⣿   ЫЫЫ,       ⢸⡇
           ⣿              ⢸⡇
           ⠿  Мы профи    ⠸⠇
 * 
 * 
 * 
 * ля, завтра продолжу
 */

#define DISABLE_CODE_FOR_RECEIVER  // в кратце, отключает код когда датчик е используется
#define SEND_PWM_BY_TIMER//виртуальный таймер
#define IR_TX_PIN 19//пин ir лампчки

#include "M5StickCPlus2.h"// библеотека стика
#include <IRremote.hpp>  // библеотека пульта

uint8_t sCommand = 0x34;//ну вообщем не знаю как точно написаь но в ir там своя кодировка сигналов и это тот сигнал с которого будет начинаться перебор сигналов назовем эту переменную переменная начального сигнала
uint8_t sRepeats = 0;//Повторы

void setup() {
    auto cfg = M5.config();//конфиг
    StickCP2.begin(cfg);//инициализация
    StickCP2.Display.setRotation(1);//угол поворота дисплея
    StickCP2.Display.setTextColor(GREEN);//цвет текста
    StickCP2.Display.setTextDatum(middle_center);//расположение текста
    StickCP2.Display.setTextFont(&fonts::Orbitron_Light_24);//шрифт текста
    StickCP2.Display.setTextSize(1);//размер текста

    IrSender.begin(DISABLE_LED_FEEDBACK);  //выключаем ir лампочку
    IrSender.setSendPin(IR_TX_PIN);//назначаем пин лампочки
}

void loop() {

    Serial.println();//вывести пробел в монитор порта
    Serial.print(F("Send now: address=0x1111, command=0x"));//вывести в монитор порта "отправляется сейчас адресс=0х1111, комманда=0х"
    Serial.print(sCommand, HEX);//вывети в монитор 
    Serial.print(F(", repeats="));//вывести вмонитор порта ", повторы="
    Serial.print(sRepeats);//вывести переменную повторов
    Serial.println();//вывести пробел в монитор порта

    StickCP2.Display.clear();//очистить дисплей
    StickCP2.Display.drawString("IR NEC SEND", StickCP2.Display.width() / 2,
                                StickCP2.Display.height() / 2 - 40);//вывести на дисплей ir отправка

    StickCP2.Display.drawString("ADDR:0x1111", StickCP2.Display.width() / 2,
                                StickCP2.Display.height() / 2);//вывести на дисплей адресс:0х1111

    StickCP2.Display.drawString("CMD:0x" + String(sCommand, HEX),
                                StickCP2.Display.width() / 2,
                                StickCP2.Display.height() / 2 + 40);//вывести на дисплей CMD:0х переменная начального сигнала

    Serial.println(F("Send standard NEC with 16 bit address"));//вывести в монитор порта отправка стандартного NEC для 16 битного адресса

    StickCP2.Display.fillCircle(32, 105, 8, GREEN);//вывести зеленый круг
    IrSender.sendNEC(0x1111, sCommand, sRepeats);//назначение стандартного NEC 0х1111, назначение переменной начального сигнала, назначение переменной повтора
    sCommand += 1;//+1 к переменной начального сигнала
    delay(500);//задержка пол секунды
    StickCP2.Display.fillCircle(32, 105, 8, YELLOW);//перекрасить кружок в желтый
    delay(500);//задержка пол секунды
}
