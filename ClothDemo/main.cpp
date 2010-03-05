#include <Cloth/Cloth.h>

#include <fstream>
#include <iomanip>
#include <iostream>

const char* HEADER = 
"import math\n"
"import cairo\n"
"\n"
"WIDTH, HEIGHT = 800, 800\n"
"PAD = 20\n"
"\n"
"surface = cairo.ImageSurface (cairo.FORMAT_ARGB32, WIDTH, HEIGHT)\n"
"ctx = cairo.Context (surface)\n"
"\n"
"ctx.rectangle(0, 0, WIDTH, HEIGHT)\n"
"ctx.set_source_rgb(1, 1, 1)\n"
"ctx.fill()\n"
"\n"
/*"ctx.rectangle(PAD, PAD, WIDTH - 2 * PAD, HEIGHT - 2 * PAD)\n"
"ctx.set_source_rgb(0, 0, 0)\n"
"ctx.stroke()\n"
"\n"*/
"ctx.translate(0, HEIGHT)\n"
"ctx.scale(1, -1)\n"
"\n"
"ctx.translate(PAD, PAD)\n"
"ctx.scale((WIDTH - 2 * PAD) / 10, (HEIGHT - 2 * PAD) / 10)\n"
"ctx.translate(5, 5)\n"
"\n"
"dx, dy = ctx.device_to_user_distance(2.0, 0.0)\n"
"ctx.set_line_width(dx)\n"
"\n";

void dump(std::ostream& stream, const Cloth::Simulation& s) {
	static int n = 0;
	
	stream 
		<< "ctx.rectangle(-5, -5, 10, 10)" << std::endl
		<< "ctx.set_source_rgb(1, 1, 1)" << std::endl
		<< "ctx.fill_preserve()" << std::endl
		<< "ctx.set_source_rgb(0, 0, 0)" << std::endl
		<< "ctx.stroke()" << std::endl
		<< std::endl;
	for (unsigned i = 0; i < s.numConstraints(); i++) {
		const Cloth::Constraint& c = s.constraint(i);
		stream
			<< "ctx.move_to( " << c.a().x() << ", " << c.a().y() << ')' << std::endl
			<< "ctx.line_to( " << c.b().x() << ", " << c.b().y() << ')' << std::endl
			<< "ctx.stroke()" << std::endl
			<< std::endl;
	}
	stream
		<< "print 'writing dump" << n << ".png'" << std::endl
		<< "surface.write_to_png('dump" << std::setw(3) << std::setfill('0') << n << ".png')" << std::endl
		<< std::endl;

	n += 1;

	/*for (unsigned i = 0; i < s.numPoints(); i++) {
		std::cout << s.point(i).pos() << std::endl;
	}
	std::cout << std::endl;*/
}

int main(void) {

	int nrows = 10;
	int ncols = nrows;
	float clen = 4.0f  / (nrows - 1);
	float sep = 4.0f / (nrows - 1);

	Cloth::Simulation s;	
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			s.addPoint(-2.0f + j * sep, 4.0f - i * sep, 0.0f);
		}
	}
	s.point(0).setFixed(true);
	s.point(ncols - 1).setFixed(true);

	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			if (j > 0) {
				s.addConstraint(ncols * i + j, ncols * i + j - 1, clen);
			}
			if (i > 0) {
				s.addConstraint(ncols * i + j, ncols * (i - 1) + j, clen);
			}
		}
	}
	

	/*s.addConstraint(0, 1, 1.0f);
	//s.addConstraint(0, 2, 1.0f);
	s.addConstraint(1, 2, 1.0f);
	//s.addConstraint(1, 3, 1.0f);
	s.addConstraint(2, 3, 1.0f);*/

	s.setGravity(0.0f, -0.005f, 0.0f);
	s.setBounds(-5.0f, -5.0f, 0.0f, 5.0f, 5.0f, 0.0f);

	std::ofstream out("dump.py");

	out << HEADER;

	for (int i = 0; i < 200; i++) {
		s.tick();
		dump(out, s);
	}
	
}