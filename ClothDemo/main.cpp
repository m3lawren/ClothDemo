#include <Cloth/Cloth.h>

#include <iostream>
#include <vector>

int main(void) {
	std::vector<Cloth::Point*> points;
	std::vector<Cloth::Constraint*> constraints;
	points.push_back(new Cloth::Point(0.0f, 0.0f, 0.0f));
	points.push_back(new Cloth::Point(2.0f, 0.0f, 0.0f));
	points.push_back(new Cloth::Point(0.0f, 2.0f, 0.0f));

	for (std::vector<Cloth::Point*>::const_iterator i = points.begin(); i != points.end(); i++) {
		for (std::vector<Cloth::Point*>::const_iterator j = i + 1; j != points.end(); j++) {
			constraints.push_back(new Cloth::Constraint(**i, **j, 1.0f));
		}
	}

	for(std::vector<Cloth::Constraint*>::const_iterator i = constraints.begin(); i != constraints.end(); i++) {
		delete *i;
	}

	for(std::vector<Cloth::Point*>::const_iterator i = points.begin(); i != points.end(); i++) {
		delete *i;
	}
	
}