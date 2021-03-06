
#include "Block.h"


Block::Block(int y, int x)
 : _position({x, y}), _canRotate(true), _array(5, vector<int>(5, BlockType::Normal)), _hasChanged(true) {}

void Block::MoveBy(int dy, int dx) {
	_position.x += dx;
	_position.y += dy;
	
	setChanged(true);
}

void Block::Rotate() {
	if (!_canRotate) return;
	auto tempArray(_array);
	
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			_array[i][j] = tempArray[4 - j][i];
		}
	}
	setChanged(true);
}

void Block::UnRotate() {
	if (!_canRotate) return;
	auto tempArray(_array);
	
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			_array[i][j] = tempArray[j][4 - i];
		}
	}
	setChanged(true);
}

const Point& Block::getLocation() { return _position; }

const vector<vector<int> >& Block::getArray() { return _array; }

void Block::setChanged(bool ok) { _hasChanged = ok; }

bool Block::hasChanged() { return _hasChanged; }

