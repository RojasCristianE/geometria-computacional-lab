/* ──────────────────────────────────────────────────────────────
 * main.c – Programa de prueba · Geometría Computacional
 * Autor:  Cristian Rojas (@RojasCristianE)
 *
 * Usa las mismas llamadas de WinBGIm (graphics.h), pero se
 * compila contra SDL_BGI para funcionar en Linux / Codespaces.
 * ────────────────────────────────────────────────────────────── */

#include <graphics.h>

int main(void)
{
    int gd = DETECT, gm;

    /* Inicializar ventana gráfica (640×480 por defecto) */
    initgraph(&gd, &gm, "");

    /* ── Título ──────────────────────────────────────────── */
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(150, 20, "Geometria Computacional");

    /* ── Ejes coordenados ────────────────────────────────── */
    setcolor(DARKGRAY);
    line(320, 0, 320, 480);   /* eje Y */
    line(0, 240, 640, 240);   /* eje X */

    /* ── Triángulo ───────────────────────────────────────── */
    setcolor(CYAN);
    line(200, 350, 440, 350); /* base              */
    line(200, 350, 320, 150); /* lado izquierdo     */
    line(440, 350, 320, 150); /* lado derecho       */

    /* ── Circunferencia circunscrita ─────────────────────── */
    setcolor(YELLOW);
    circle(320, 283, 120);

    /* ── Punto central ───────────────────────────────────── */
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(320, 283, 5, 5);

    /* ── Etiquetas ───────────────────────────────────────── */
    setcolor(LIGHTGREEN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(180, 360, "A(200,350)");
    outtextxy(420, 360, "B(440,350)");
    outtextxy(300, 130, "C(320,150)");

    /* Esperar a que el usuario cierre la ventana */
    getch();
    closegraph();

    return 0;
}
