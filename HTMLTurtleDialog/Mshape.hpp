#include "stdafx.h"
#include <sac.h>

namespace EunMfc {
	class RGB {
	public:
		using RGBCOLOR = int;

		void setColor(int r, int g, int b) {
			rgb = static_cast<RGBCOLOR>(RGB(r, g, b));
		}

		template <typename T>
		RGBCOLOR setColor(T&& point) {
			rgb = point;
			return rgb;
		}
		operator int() {
			return rgb;
		}
	private:
		RGBCOLOR rgb;

	};
}