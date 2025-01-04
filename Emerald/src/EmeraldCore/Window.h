#pragma once

#include <stdint.h>
#include <string>

namespace Emerald {

	class IWindow {
	public:
		virtual ~IWindow() = default;
		virtual void OnUpdate() = 0;
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void* GetNativeWindow() const = 0;

	protected:
		uint32_t m_Width = 0;
		uint32_t m_Height = 0;
		std::string m_Title = "";
	};
}