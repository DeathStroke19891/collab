{ pkgs,nixpkgs ? { } }:

pkgs.mkShell
{
  nativeBuildInputs = [
    pkgs.trashy
    pkgs.clang-tools
    pkgs.cmake
    pkgs.gnumake
    pkgs.qt6.full
    pkgs.gdb
    pkgs.libcxx
  ];

  buildInputs = [
    pkgs.qtcreator
  ];
  shellHook = ''
    alias rm="trash -c always put"
    export QT_QPA_PLATFORM=wayland
  '';
}
