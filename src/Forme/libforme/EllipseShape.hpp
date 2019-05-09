#include "SFML/Graphics.hpp"

class EllipseShape : public sf::Shape {
	sf::Vector2f m_size;

	public:

		explicit EllipseShape(const sf::Vector2f& size = sf::Vector2f(0.f, 0.f)) :
			m_size(size)
		{
			update();
		}

		void setRadius(const sf::Vector2f& size)
		{
			m_size = size;
			update();
		}

		const sf::Vector2f& getSize() const
		{
			return m_size;
		}

		virtual std::size_t getPointCount() const
		{
			return 30; // fixé, mais ça pourrait tout aussi bien être un attribut de la classe
		}

		virtual sf::Vector2f getPoint(std::size_t index) const
		{
			static const float pi = 3.141592654f;

			float angle = index * 2 * pi / getPointCount() - pi / 2;
			float x = std::cos(angle) * m_size.x;
			float y = std::sin(angle) * m_size.y;

			return sf::Vector2f(m_size.x + x, m_size.y + y);
		}
};