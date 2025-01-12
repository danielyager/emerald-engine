#pragma once

#include "EmeraldCore/Layer.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
//#include "backends/imgui_impl_opengl3_loader.h"
#include "EmeraldCore/Application.h"

namespace Emerald {

	class EMERALD_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;

	private:
		float m_Time = 0.0f;
	};
}