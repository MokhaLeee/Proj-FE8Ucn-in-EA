@echo off

@cd %~dp0/Glyph
@del *.dmp
@del *.gba


echo Make Png2Dmp!
@dir *.png /b > png.txt
@for /f "tokens=*" %%m in (png.txt) do Png2Dmp %%m
@del png.txt
echo Png2Dmp Done!


echo Make Dmp2Font!
@for %%i in (*) do ( Dmp2Font %%i )
echo Dmp2Font Done!
@del *.dmp


pause