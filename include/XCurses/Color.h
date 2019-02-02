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
	 * \brief Move Color contructor
	 */
	Color(Color&&) = default;

    /**
	 * \brief Overload of the binary = operator
	 * \param right Right operand
	 * \return 
	 */
	Color& operator =(const Color& right);

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

/**
 * \brief Overload of the == operator
 * This operator compares two colors and check if they are equal.
 * \param left Left operand
 * \param right Right operand
 * \return True if colors are equal, false if they are different
 */
bool operator ==(const Color& left, const Color& right);

/**
 * \brief Overload of the != operator
 * This operator compares two colors and check if they are different.
 * \param left Left operand
 * \param right Right operand
 * \return True if colors are different, false if they are equal
 */
bool operator !=(const Color& left, const Color& right);

/**
 * \brief Overload of the binary + operator
 * This operator returns the component-wise sum of two colors.
 * Components that exceed 255 are clamped to 255.
 * \param left Left operand
 * \param right Right operand
 * \return Result of \a left + \a right
 */
Color operator +(const Color& left, const Color& right);

/**
 * \brief Overload of the binary - operator
 * This operator returns the component-wise subtraction of two colors.
 * Components below 0 are clamped to 0.
 * \param left Left operand
 * \param right Right operand
 * \return Result of \a left - \a right
 */
Color operator -(const Color& left, const Color& right);

/**
 * \brief Overload of the binary * operator
 * This operator returns the component-wise multiplication
 * (also called "modulation") of two colors.
 * Components are then divided by 255 so that the result is
 * still in the range [0, 255].
 * \param left Left operand
 * \param right Right operand
 * \return Result of \a left * \a right
 */
Color operator *(const Color& left, const Color& right);

/**
 * \brief Overload of the binary += operator
 * This operator computes the component-wise sum of two colors,
 * and assigns the result to the left operand.
 * Components that exceed 255 are clamped to 255.
 * \param left Left operand
 * \param right Right operand
 * \return Reference to \a left
 */
Color& operator +=(Color& left, const Color& right);

/**
 * \brief Overload of the binary -= operator
 * This operator computes the component-wise subtraction of two colors,
 * and assigns the result to the left operand.
 * Components below 0 are clamped to 0.
 * \param left Left operand
 * \param right Right operand
 * \return Reference to \a left
 */
Color& operator -=(Color& left, const Color& right);

/**
 * \brief Overload of the binary *= operator
 * This operator returns the component-wise multiplication
 * (also called "modulation") of two colors, and assigns
 * the result to the left operand.
 * Components are then divided by 255 so that the result is
 * still in the range [0, 255].
 * \param left Left operand
 * \param right Right operand
 * \return Reference to \a left
 */
Color& operator *=(Color& left, const Color& right);
}