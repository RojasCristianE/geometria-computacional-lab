# 📐 Geometría Computacional – Entorno SDL_BGI

> **Autor:** Cristian Rojas · [github.com/RojasCristianE](https://github.com/RojasCristianE)

Repositorio base para la clase de **Geometría Computacional**.  
Usa **SDL_BGI** (`graphics.h`) para ser **100% compatible** con el código WinBGIm de clase, pero compilable en **Linux, macOS y GitHub Codespaces**.

---

## 🚀 Inicio rápido en GitHub Codespaces

1. **Crea un Codespace** desde este repositorio (botón verde `<> Code` → `Codespaces`).
2. Espera a que termine el build del contenedor (~2 min, instala SDL2 + SDL_BGI).
3. Compila y ejecuta:

   ```bash
   make run
   ```

4. **Ver la salida gráfica:**
   - El puerto **6080** se abre automáticamente.
   - Haz clic en la notificación o ve a la pestaña **Ports** → puerto `6080` → *Open in Browser*.
   - Verás un escritorio virtual (NoVNC) con la ventana gráfica SDL.

> **Contraseña del VNC:** `cristian`

---

## 🖥️ Configuración local (Ubuntu / WSL2)

```bash
# 1. Instalar dependencias
sudo apt update && sudo apt install -y libsdl2-dev git build-essential

# 2. Compilar e instalar SDL_BGI
git clone --depth 1 https://github.com/genpfault/sdl-bgi.git /tmp/SDL_bgi
cd /tmp/SDL_bgi/src && make && sudo make install && sudo ldconfig

# 3. Compilar y ejecutar
cd /ruta/al/repo
make run
```

---

## 🍎 Configuración local (macOS)

```bash
# 1. Instalar SDL2 con Homebrew
brew install sdl2

# 2. Compilar e instalar SDL_BGI
git clone --depth 1 https://github.com/genpfault/sdl-bgi.git /tmp/SDL_bgi
cd /tmp/SDL_bgi/src && make && sudo make install

# 3. Compilar y ejecutar
cd /ruta/al/repo
make run
```

---

## 🪟 Compatibilidad con Windows (WinBGIm)

El código usa **únicamente** funciones estándar de `graphics.h`:

```c
#include <graphics.h>
initgraph(&gd, &gm, "");
line(x1, y1, x2, y2);
circle(x, y, r);
getch();
closegraph();
```

Para compilar en Windows con WinBGIm, usa las mismas banderas que tu profesor indica (típicamente `-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32`).

---

## 📁 Estructura del proyecto

```
.
├── .devcontainer/
│   ├── devcontainer.json   # Config de Codespaces (NoVNC + SDL_BGI)
│   └── setup.sh            # Script de instalación automática
├── .vscode/
│   └── tasks.json          # Tareas de compilación (Ctrl+Shift+B)
├── main.c                  # Programa de prueba
├── Makefile                # Build rápido desde terminal
└── README.md
```

---

## ⌨️ Atajos útiles

| Acción | Comando |
| :--- | :--- |
| Compilar todo | `make` |
| Compilar y ejecutar | `make run` |
| Limpiar binarios | `make clean` |
| Build en VSCode | `Ctrl+Shift+B` |
