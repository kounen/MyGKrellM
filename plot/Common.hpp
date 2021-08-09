#ifndef COMMON_HPP
#define COMMON_HPP

#include <exception>
#include <string>

#if defined(_MSC_VER) && (_MSC_VER < 1900)
#define NOEXCEPT
#else
#define NOEXCEPT noexcept
#endif

namespace selbaward
{

class Exception : public std::exception
{
public:
	Exception(const std::string& errorMessage = "Unknown error.") :
		m_errorMessage("[Selba Ward] " + errorMessage)
	{
	}
	virtual const char* what() const NOEXCEPT override
	{
		return m_errorMessage.c_str();
	}

private:
	std::string m_errorMessage;
};

} // namespace selbaward

#ifndef NO_NAMESPACE_SHORTCUT
namespace sw = selbaward; // create shortcut namespace
#endif // NO_NAMESPACE_SHORTCUT

#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#if (SFML_VERSION_MAJOR == 2)
	#if (SFML_VERSION_MINOR < 4)
		#define USE_SFML_PRE_2_4
	#endif
#endif

#endif // COMMON_HPP