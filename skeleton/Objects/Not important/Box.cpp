#include "Box.h"

Box::Box(Vector3 pos, Vector3 halfExtents, Vector4 color) : Object(pos), color(color) {
	physx::PxBoxGeometry geo; geo.halfExtents = halfExtents;
	shape = CreateShape(geo);
	render = new RenderItem(shape, &trans, color);
}
