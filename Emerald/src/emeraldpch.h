#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "EmeraldCore/Logger.h"

// Rendering and Windowing includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#ifdef EMERALD_PLATFORM_WINDOWS
	#include <Windows.h>
#endif