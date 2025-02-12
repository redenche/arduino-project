/*.
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
#include "M5StickCPlus2.h"

void setup() {
    auto cfg = M5.config();//конфиги текста
    StickCP2.begin(cfg);//инициализаия
    StickCP2.Display.setRotation(3);//угол поворота дисплея 
    //0 - 0градусов 1 - 90 градусов
    //2 - 180 градусов 3 - 360 градусов
    StickCP2.Display.setTextColor(GREEN);//цвет текста
    StickCP2.Display.setTextDatum(middle_center);//расположеие текста
    StickCP2.Display.setTextFont(&fonts::Orbitron_Light_24);//шрифт текста
    StickCP2.Display.setTextSize(1);//размер текста
    StickCP2.Display.drawString("Random graphics", StickCP2.Display.width() / 2,
                                StickCP2.Display.height() / 2);//просто выводим текст в начале
    delay(1500);//ждем 1 секунду
}

void loop() {
  //команда rand() сокращение  random предузомевает вообщем как работает
  //int a (добавляем переменную) = rand() % максимальное число , минимальное число
    int x         = rand() % StickCP2.Display.width();
    int y         = rand() % StickCP2.Display.height();//тут мы просто назначаем рандомную координату для x и y для нашего дисплея вообщем
    int r         = (StickCP2.Display.width() >> 4) + 2;// радиус(для круга) и длина строн дл фигур
    uint16_t c    = rand();//переменная цвета фигуры
    int shapeType = rand() % 5;  // 0: круг, 1: прямоугольник
                                 // 2: Элипс, 3: треугольник, 4: Линия

    StickCP2.Display.clear();  //очищаем дмсплей

    switch (shapeType) {//это типо if(){} но проще тут у нас просто рандомное число и тут на каждое из чисел своя комманда ща объясню
        case 0:
            StickCP2.Display.fillCircle(x, y, r, c);//если переменная равна 0 то вывести круг в таких то координатах
            break;//конец кейса
        case 1:
            StickCP2.Display.fillRect(x, y, r, r, c);//ну и там далее если переменная равна 1 вывести квадрат в таких то координатах
            break;
        case 2:
            StickCP2.Display.fillEllipse(x, y, r + 5, r, c);
            break;
        case 3:
            StickCP2.Display.fillTriangle(x, y, x + r, y + r, x - r, y + r, c);
            break;
        case 4:
            StickCP2.Display.drawLine(x, y, x + r, y + r, c);
            break;
    }
    delay(500);//задержка пол секунды(500 миллесекунд)
}
