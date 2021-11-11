echo off
del *.event
_MakeTableDef FE8U.gba
_InitFontInstaller

@cd %~dp0/Glyph
@del *.event

InitInstaller

echo Make Installer!
@for %%i in (*) do ( _MakeFontInstaller %%i "font.fontall.txt" )
del *.stackdump
echo Installer Done!



