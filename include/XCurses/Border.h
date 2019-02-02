#pragma once

#include <cstdint>

namespace xcur {
class Border
{
public:
	enum Type
	{
		None,
		Standard,
		Advanced,
		Double
	};

	Border() :
		Border(Border::Type::Advanced)
	{
	}

	Border(uint32_t _leftSide,
		uint32_t _rightSide,
		uint32_t _topSide,
		uint32_t _bottomSide,
		uint32_t _topLeftCorner,
		uint32_t _topRightCorner,
		uint32_t _bottomLeftCorner,
		uint32_t _bottomRightCorner
	) :
		leftSide(_leftSide),
		rightSide(_rightSide),
		topSide(_topSide),
		bottomSide(_bottomSide),
		topLeftCorner(_topLeftCorner),
		topRightCorner(_topRightCorner),
		bottomLeftCorner(_bottomLeftCorner),
		bottomRightCorner(_bottomRightCorner)
	{
	}

	Border(Border::Type type)
	{
		switch (type) {
		case Border::Type::None:
		{
			this->fill(' ');
			break;
		}
		case Border::Type::Standard:
		{
			leftSide = '|';
			rightSide = '|';
			topSide = '-';
			bottomSide = '-';
			topLeftCorner = '+';
			topRightCorner = '+';
			bottomLeftCorner = '+';
			bottomRightCorner = '+';
			break;
		}
		case Border::Type::Advanced:
		{

			leftSide = 0x2502;
			rightSide = 0x2502;
			topSide = 0x2500;
			bottomSide = 0x2500;
			topLeftCorner = 0x250c;
			topRightCorner = 0x2510;
			bottomLeftCorner = 0x2514;
			bottomRightCorner = 0x2518;
			break;
		}
		case Border::Type::Double:
		{

			leftSide = 0x2551;
			rightSide = 0x2551;
			topSide = 0x2550;
			bottomSide = 0x2550;
			topLeftCorner = 0x2554;
			topRightCorner = 0x2557;
			bottomLeftCorner = 0x255a;
			bottomRightCorner = 0x255d;
			break;
		}
		}
	}

	void fill(uint32_t c)
	{
		leftSide = c;
		rightSide = c;
		topSide = c;
		bottomSide = c;
		topLeftCorner = c;
		topRightCorner = c;
		bottomLeftCorner = c;
		bottomRightCorner = c;
	}

	uint32_t leftSide;
	uint32_t rightSide;
	uint32_t topSide;
	uint32_t bottomSide;
	uint32_t topLeftCorner;
	uint32_t topRightCorner;
	uint32_t bottomLeftCorner;
	uint32_t bottomRightCorner;
};
}