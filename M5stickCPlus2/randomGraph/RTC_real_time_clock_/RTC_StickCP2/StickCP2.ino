/*Всем щалом, я разбирался с этой библиотекой и по этогу разобралася, вот код часов для StickCplus2
 * примечания!!!
 * ПОСЛЕ ВЫКЛЮЧЕНИЯ СТИКА ПОЛНОСТЬЮ ЧАСЫ ОТКТАТЫВАЮТСЯ ДО НАЧАЛЬНЫХ ДАННЫХ
 * это можно починить и сделать настраиваемое меню, уход в сонный режим и можно использовать интернет часы, но для них интернет нужен, как бы это странно не звучало
 * .
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
 */


//начало кода

#include <M5StickCPlus2.h>//подключение библиотеки стика
#include <ESP32Time.h>//подключение библиотеки часов
//ESP32Time rtc(3600);
ESP32Time rtc;//настройка разности времени, пока я её заменил на эту комнду тк она нам бесполезна
void setup() {
 M5.begin();//инициализация дисплея стика
 M5.Lcd.setRotation(1);//угол поворота стика
 rtc.setTime(20, 9, 0, 13, 2, 2024);//настройка времени
 //1. секунды     4.день(дата)
 //2. минуты      5.месяц
 //3. часы        6.год
 M5.Lcd.setTextColor(GOLD);//цвет текста(я золотой по приколу поставил)
M5.Lcd.setTextFont(&fonts::TomThumb);//шрифт текста(я пиксельный поставил)
M5.Lcd.setTextSize(3);//размер текста, вот тут я уже поставил 3 потому что шрифт в 1 размере слишком маленький
}

void loop() {
  M5.Lcd.setCursor(23, 23);//координаты текста/часов
      M5.Lcd.print(rtc.getTime());//вывести на дисплей время
delay(1000);//подождать 1 секунду !!! важно, иначе будут артефакты
M5.Lcd.clear();//очистить дисплей !!! тоже важно, числа будут песататься друг на друг на друге
}//конец кода
