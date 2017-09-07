// smallpaint by karoly zsolnai - zsolnai@cg.tuwien.ac.at
//
// render, modify, create new scenes, tinker around, and most of all:
// have fun!
//
// This program is used as an educational learning tool on the Rendering
// course at TU Wien. Course webpage:
// http://cg.tuwien.ac.at/courses/Rendering/
//
// This UI serves as an educational learning tool to see the progressions
// and experience the different renderes with different input.
// Created by Michael Oppitz - e1227129@student.tuwien.ac.at

#include <QApplication>
#include <mainwindow.h>

/**
 * Creates new MainWindow and sets instances.
 */
int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow *w = new MainWindow;
	setInstanceForRenderDistribution(w);
	setInstanceForHelperFunctions(w);
	w->show();
	return a.exec();
}
