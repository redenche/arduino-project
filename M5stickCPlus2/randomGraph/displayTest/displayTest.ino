/**
*я немнрго подправил код но если вы хотите то можете исправить и результат будет тот же
*
*тест дисплея
 */

#include "M5StickCPlus2.h"//добавление библиотеки стика

/*void draw_function(LovyanGFX* gfx) {//тут используется новая функция, но я делал проще в loop(){}
    int x      = rand() % gfx->width();
    int y      = rand() % gfx->height();
    int r      = (gfx->width() >> 4) + 2;
    uint16_t c = rand();
    gfx->fillRect(x - r, y - r, r * 2, r * 2, c);
}
*/
void setup() {
    auto cfg = M5.config();//конфиг
    StickCP2.begin(cfg);//инициализация
    int textsize = StickCP2.Display.height() / 60;//пременная = высота дисплея стика делить на 60
    if (textsize == 0) {
      //если пременная равна 0
        textsize = 1;//назначить переменной значение 1
    }
    StickCP2.Display.setTextSize(textsize);//размер текста = пременая
}

void loop() {
  int x2      = rand() % StickCP2.Display.width();//рандомные координаты квадрата
    int y2     = rand() % StickCP2.Display.height();
    int r2      = (StickCP2.Display.width() >> 4) + 2;//радиус(сторона) квадрата
    uint16_t c2 = rand();//цвет квадрата
    int x      = rand() % StickCP2.Display.width();//рандомные координаты круга
    int y      = rand() % StickCP2.Display.height();
    int r      = (StickCP2.Display.width() >> 4) + 2;//радиус круга
    uint16_t c = rand();//цвт круга
    StickCP2.Display.fillCircle(x, y, r, c);//вывести круг
    StickCP2.Display.fillRect(x2 - r2, y2 - r2, r2 * 2, r2 * 2, c2);//вывести квадрат
    //draw_function(&StickCP2.Display);//если кто-то хочет вернуть ту фунцию не забудте раскоментить эту комманду
}
