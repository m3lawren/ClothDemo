#include "Simulation.h"

#include "Point.h"

#include <algorithm>

namespace Cloth {

	Simulation::Simulation() {
	}

	Simulation::~Simulation() {
		for (cvec_t::iterator iter = _constraints.begin(); iter != _constraints.end(); iter++) {
			delete *iter;
		}

		for (pvec_t::iterator iter = _points.begin(); iter != _points.end(); iter++) {
			delete *iter;
		}
	}

	void Simulation::tick() {
		for (pvec_t::iterator iter = _points.begin(); iter != _points.end(); iter++) {
			(*iter)->tick(_gravity);
		}

		for (int i = 0; i < 1; i++) {
			if (i % 2) {
				for (cvec_t::iterator iter = _constraints.begin(); iter != _constraints.end(); iter++) {
					(*iter)->enforce();
				}
			} else {
				for (cvec_t::reverse_iterator iter = _constraints.rbegin(); iter != _constraints.rend(); iter++) {
					(*iter)->enforce();
				}
			}

			for (cvec_t::iterator iter = _constraints.begin(); iter != _constraints.end(); iter++) {
				(*iter)->enforce();
			}
			
			for (pvec_t::iterator iter = _points.begin(); iter != _points.end(); iter++) {
				_bounds.enforceOn(**iter);
			}
		}
	}

	void Simulation::clear() {
		_bounds.init(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
		_gravity = Cloth::Vector3();

		for (cvec_t::iterator i = _constraints.begin(); i != _constraints.end(); i++) {
			delete *i;
		}

		for (pvec_t::iterator i = _points.begin(); i != _points.end(); i++) {
			delete *i;
		}

		_constraints.clear();
		_points.clear();
		_indices.clear();
	}
	
	unsigned Simulation::addPoint(float x, float y, float z) {
		_points.push_back(new Cloth::Point(x, y, z));
		return _points.size() - 1;
	}

	unsigned Simulation::addPoint(const Cloth::Vector3& p) {
		_points.push_back(new Cloth::Point(p));
		return _points.size() - 1;
	}

	unsigned Simulation::addFixed(float x, float y, float z) {
		_points.push_back(new Cloth::Point(x, y, z));
		_points.back()->setFixed(true);
		return _points.size() - 1;
	}

	unsigned Simulation::addFixed(const Cloth::Vector3& p) {
		_points.push_back(new Cloth::Point(p));
		_points.back()->setFixed(true);
		return _points.size() - 1;
	}

	void Simulation::addConstraint(unsigned a, unsigned b) {
		_constraints.push_back(new Cloth::Constraint(*_points[a], *_points[b]));
		_indices.push_back(std::pair<unsigned,unsigned>(a,b));
	}

	void Simulation::setGravity(float dx, float dy, float dz) {
		setGravity(Cloth::Vector3(dx, dy, dz));
	}

	void Simulation::setGravity(const Cloth::Vector3& v) {
		_gravity = v;
	}

	void Simulation::setBounds(float x1, float y1, float z1, float x2, float y2, float z2) {
		_bounds.init(x1, y1, z1, x2, y2, z2);
	}

	unsigned Simulation::numPoints() const {
		return _points.size();
	}

	Cloth::Point& Simulation::point(unsigned i) {
		return *_points[i];
	}

	const Cloth::Point& Simulation::point(unsigned i) const {
		return *_points[i];
	}

	unsigned Simulation::numConstraints() const {
		return _constraints.size();
	}

	const std::pair<unsigned,unsigned>& Simulation::constraint(unsigned i) const {
		return _indices[i];
	}

}