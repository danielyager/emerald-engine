#include "emeraldpch.h"
#include "LayerStack.h"

namespace Emerald {

	LayerStack::~LayerStack() {
		for (Layer* layer : m_Layers) {
			layer->OnDetach();
			delete layer;
		}
		for (Layer* layer : m_Overlays) {
			layer->OnDetach();
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer) {
		m_Layers.emplace_back(layer);
	}

	void LayerStack::PushOverlay(Layer* layer) {
		m_Overlays.emplace_back(layer);
	}

	void LayerStack::PopLayer() {
		m_Layers.pop_back();
	}

	void LayerStack::PopOverlay() {
		m_Overlays.pop_back();
	}

	void LayerStack::UpdateLayersAndOverlays() {
		for (Layer* layer : m_Layers) {
			layer->OnUpdate();
		}
		for (Layer* layer : m_Overlays) {
			layer->OnUpdate();
		}
	}

}