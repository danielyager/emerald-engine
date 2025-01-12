#include "emeraldpch.h"
#include "ImGuiLayer.h"

namespace Emerald {

	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {
	}

	ImGuiLayer::~ImGuiLayer() {
	}

	void ImGuiLayer::OnAttach() {
        IMGUI_CHECKVERSION();
		ImGui::SetCurrentContext(ImGui::CreateContext());

		if (!(ImGui::GetCurrentContext())) {
			LOG_ERROR("ImGui Current Context is NULL!");
		}

		ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

        ImGui::StyleColorsDark();

		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		if (!window) {
			LOG_ERROR("The GLFWwindow in ImGuiLayer OnAttach() is NULL!");
			return;
		}

		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init();
	}

	void ImGuiLayer::OnDetach() {
		LOG_WARN("In OnDetach for ImGui.");
		if ((ImGui::GetCurrentContext()) == nullptr) {
			LOG_ERROR("ImGui Current Context is NULL in beginning of OnDetach()!");
			return;
		}
		ImGui::SetCurrentContext(ImGui::GetCurrentContext());

		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
		LOG_TRACE("Completed running OnDetach() for ImGuiLayer.");
	}

	void ImGuiLayer::OnUpdate() {
		if (!(ImGui::GetCurrentContext())) {
			LOG_ERROR("ImGui Current Context is NULL in beginning of OnUpdate()!");
		}

		ImGuiIO& io = ImGui::GetIO();
		GLWindow& appWindow = Application::Get().GetWindow();
		io.DisplaySize = ImVec2(appWindow.GetWidth(), appWindow.GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}
}