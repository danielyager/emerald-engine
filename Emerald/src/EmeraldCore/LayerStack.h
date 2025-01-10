#pragma once

#include "EmeraldCore/Core.h"
#include "EmeraldCore/Layer.h"

namespace Emerald {

	class EMERALD_API LayerStack {
	public:
		LayerStack() = default;
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void PopLayer();
		void PopOverlay();

		void UpdateLayersAndOverlays();

		//inline std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		//inline std::vector<Layer*>::iterator end() { return m_Layers.end(); }
		//inline std::vector<Layer*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
		//inline std::vector<Layer*>::reverse_iterator rend() { return m_Layers.rend(); }

	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*> m_Overlays;
	};
}