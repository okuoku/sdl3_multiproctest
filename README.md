# Clone

`git clone --recursive https://github.com/okuoku/sdl3_multiproctest`

# Prerequisites

```
sudo apt-get install build-essential \
pkg-config cmake ninja-build libasound2-dev libpulse-dev \
libaudio-dev libjack-dev libsndio-dev libx11-dev libxext-dev \
libxrandr-dev libxcursor-dev libxfixes-dev libxi-dev libxss-dev libxtst-dev \
libxkbcommon-dev libdrm-dev libgbm-dev libgl1-mesa-dev libgles2-mesa-dev \
libegl1-mesa-dev libdbus-1-dev libibus-1.0-dev libudev-dev \
libpipewire-0.3-dev libwayland-dev libdecor-0-dev liburing-dev
```

# Build

`cmake -G Ninja -B build -S .` and build

# Run (Linux + Wayland + X11)

## WSLg Configuration

```
ln -s /mnt/wslg/runtime-dir/wayland-0* /run/user/1000/
```

see https://github.com/microsoft/WSL/issues/11261#issuecomment-2156226512

## Xwayland

`Xwayland :2 -decorate -geometry 1024x1024 -shm`

# Run (macOS)

TBD

# Run (Win32)

TBD
