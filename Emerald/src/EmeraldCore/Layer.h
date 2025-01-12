#pragma once

#include "EmeraldCore/Core.h"
#include "EmeraldCore/Events/Event.h"

namespace Emerald {

	class EMERALD_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}

		inline const std::string& GetName() const { return m_LayerName; }

	protected:
		std::string m_LayerName;

	};
}