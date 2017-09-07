smallpaint by karoly zsolnai - zsolnai@cg.tuwien.ac.at

render, modify, create new scenes, tinker around, and most of all:
have fun!

This program is used as an educational learning tool on the Rendering
course at TU Wien. Course webpage:
http://cg.tuwien.ac.at/courses/Rendering/

This UI serves as an educational learning tool to see the progressions
and experience the different renderes with different input.
created by Michael Oppitz  - e1227129@student.tuwien.ac.at	
				
Building (Windows):
	- If you didn't already: Download and install Qt 5.7 and don't forget to check MinGW during installation:
				- Qt 5.7 (for MinGW) for Windows: http://download.qt.io/official_releases/qt/5.7/5.7.0/qt-opensource-windows-x86-mingw530-5.7.0.exe.mirrorlist
				- Add "%PATHTOQT%\Qt\Qt5.7.0\5.7\mingw53_32\bin" and "%PATHTOQT%\\Qt\Qt5.7.0\Tools\mingw530_32\bin" to the PATH variable.
				- Add a new variable called QTDIR with the value "%PATHTOQT%\Qt\Qt5.7.0\5.7\mingw53_32".
	- Start a shell and cd into the "binary_win32" folder.
	- Remove everything that is there.
	- Call the commands:
				qmake.exe ..\src_gui\Smallpaint.pro -r -spec win32-g++
				mingw32-make.exe -j4
				move release/Smallpaint.exe
	- Remove everything, but the "Smallpaint.exe".
	- Call the command: 
				windeployqt.exe . 				(the dot is important)
	- If you are missing some dependencies look for them in the dependecy folder or online.

Building (Linux):
	- If you didn't already: Download and install Qt 5.7:
				- Qt 5.7 for Linux: http://download.qt.io/official_releases/qt/5.7/5.7.0/qt-opensource-linux-x64-5.7.0.run.mirrorlist
	- Remove everything in the "binary_linux" folder and open a terminal there.
	- Call the commands:
				%PATHTOQT%/Qt5.7.0/5.7/gcc_64/bin/qmake ../src_gui
				make -j4
				./Smallpaint
	- If you're missing some dependencies, run "ldd Smallpaint" (without the quotes) and see what it links to.