#include <graphics.h>

int main() {
    // Inicializar la ventana gráfica (Ancho, Alto)
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    // Dibujar una línea desde la coordenada (100, 100) hasta (300, 300)
    line(100, 100, 300, 300);

    // Dibujar un círculo con centro en (200, 200) y radio 50
    circle(200, 200, 50);

    // Esperar a que el usuario presione una tecla
    getch();

    // Cerrar el modo gráfico
    closegraph();
    return 0;
}
