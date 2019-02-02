#pragma once

#include <cstdint>

namespace xcur {
/**
 * \brief PDCurses color standard defines that the color component must be
 * between 0 and 1000. This class stored color with component between 0 and 255.
 */
class Color
{
public:
    /**
	 * \brief Default Color contructor. Creates Color(0, 0, 0) that means black
	 * color
	 */
	Color();

    /**
	 * \brief Constructor the color from its 3 RGB components
	 * \param red Red component (in the range [0, 255])
	 * \param green Green component (in the range [0, 255])
	 * \param blue Blue component (in the range [0, 255])
	 */
	Color(uint8_t red, uint8_t green, uint8_t blue);

    /**
	 * \brief Contruct the color from 32-bit unsigned integer
	 * \param color Number containing the RGB components (in that order).
	 * Format is 0x00ffffff
	 */
	explicit Color(uint32_t color);

	/**
	 * \brief Copy Color contructor
	 */
	Color(const Color&) = default;

	/**
	 * \brief Move Color contructor
	 */
	Color(Color&&) = default;

	/**
	 * \brief Color destructor
	 */
	~Color() = default;

	static const Color Black;       //< Black predefined color
	static const Color White;       //< White predefined color
	static const Color Red;         //< Red predefined color
	static const Color Green;       //< Green predefined color
	static const Color Blue;        //< Blue predefined color
	static const Color Yellow;      //< Yellow predefined color
	static const Color Magenta;     //< Magenta predefined color
	static const Color Cyan;        //< Cyan predefined color

    /**
	 * \brief Translates color component from [0, 255] to [0, 1000]
	 * \return Red color component
	 */
	inline uint16_t cursesRed();

	/**
	 * \brief Translates color component from [0, 255] to [0, 1000]
	 * \return Green color component
	 */
	inline uint16_t cursesGreen();

	/**
	 * \brief Translates color component from [0, 255] to [0, 1000]
	 * \return Blue color component
	 */
	inline uint16_t cursesBlue();

    /**
	 * \brief Red component in color
	 */
	uint8_t r;

	/**
	 * \brief Green component in color
	 */
	uint8_t g;

	/**
	 * \brief Blue component in color
	 */
	uint8_t b;
};
}