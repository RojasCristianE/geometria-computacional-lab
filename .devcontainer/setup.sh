#!/usr/bin/env bash
# ──────────────────────────────────────────────────────────────
# setup.sh – Installs SDL2 and SDL_BGI from source.
# Runs automatically via devcontainer postCreateCommand.
# ──────────────────────────────────────────────────────────────
set -euo pipefail

echo "▶ Installing SDL2 development libraries..."
sudo apt-get update -qq
sudo apt-get install -y --no-install-recommends \
  libsdl2-dev \
  libsdl2-gfx-dev \
  libsdl2-image-dev \
  libsdl2-ttf-dev \
  pkg-config

echo "▶ Cloning SDL_BGI..."
SDL_BGI_DIR="/tmp/SDL_bgi"
rm -rf "$SDL_BGI_DIR"
git clone --depth 1 https://github.com/genpfault/sdl-bgi.git "$SDL_BGI_DIR"

echo "▶ Compiling SDL_BGI..."
cd "$SDL_BGI_DIR/src"
make

echo "▶ Installing SDL_BGI system-wide..."
sudo make install

# Ensure the linker cache is up-to-date
sudo ldconfig

echo "✔ SDL_BGI installed successfully."
echo "  graphics.h → $(find /usr/local/include /usr/include -name graphics.h 2>/dev/null | head -1)"
echo "  libSDL_bgi → $(find /usr/local/lib /usr/lib -name 'libSDL_bgi*' 2>/dev/null | head -1)"
