{ pkgs,nixpkgs ? { } }:

pkgs.mkShell
{
  nativeBuildInputs = [
    pkgs.clang-tools
    pkgs.cmake
    pkgs.libcxx
  ];

  shellHook = ''
    alias rm="trash -c always put"
  '';
}
