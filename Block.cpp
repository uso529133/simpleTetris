
#include "Block.h"

Block::Block(int y, int x) : _position({x, y}), _canRotate(true), _array(y, vector<bool>(x, false)) {
	_array.assign(y, vector<bool>(x, true));
}

void Block::MoveBy(int dy, int dx) {
	_position.x += dx;
	_position.y += dy;
}

void Block::Rotate() {
	auto tempArray(_array);
	
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			_array[i][j] = tempArray[4 - i][j];
		}
	}
}

const Point* Block::getLocation() {
	return &_position;
}
