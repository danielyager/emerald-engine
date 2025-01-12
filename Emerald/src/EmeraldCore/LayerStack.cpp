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
		layer->OnAttach();
		LOG_TRACE("We are pushing a new layer to the layer stack! [Layer Name: {0}]", layer->GetName());
	}

	void LayerStack::PushOverlay(Layer* layer) {
		m_Overlays.emplace_back(layer);
		layer->OnAttach();
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

	void LayerStack::DetachLayersAndOverlays() {
		for (Layer* layer : m_Layers) {
			LOG_WARN("Detaching Layer from stack. Layer Name: [{0}]", layer->GetName());
			layer->OnDetach();
		}
		for (Layer* layer : m_Overlays) {
			LOG_WARN("Detaching Overlay from stack. Overlay Name: [{0}]", layer->GetName());
			layer->OnDetach();
		}
		m_Layers.clear();
		m_Overlays.clear();
	}

}