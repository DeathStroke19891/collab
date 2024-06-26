{ pkgs,nixpkgs ? { } }:

pkgs.mkShell
{
  nativeBuildInputs = [
    pkgs.clang-tools
    pkgs.qt6.full
    pkgs.gdb
    pkgs.libcxx
  ];

  buildInputs = [
    pkgs.qtcreator
    pkgs.trashy
  ];
  shellHook = ''
    alias rm="trash -c always put"
    export QT_QPA_PLATFORM=wayland
  '';
}
