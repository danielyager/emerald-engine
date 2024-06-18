#pragma once

#include "Event.h"
#include "../Util/KeyCodes.h"

namespace Emerald {

	class KeyEvent : Event {
	public:
		KeyCode GetKeyCode() const { return m_KeyCode; }

	protected:
		KeyCode m_KeyCode;

		KeyEvent(const KeyCode keyCode) : m_KeyCode(keyCode) {}
	};



	class KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(const KeyCode keyCode, bool isRepeat = false) : KeyEvent(keyCode), m_IsRepeat(isRepeat) {}

		bool IsRepeat() const { return m_IsRepeat; }

		std::string ToString() const override {
			std::string eventString1 = "KeyPressedEvent: " + m_KeyCode;
			std::string eventString2 = " (repeat = " + m_IsRepeat;
			return (eventString1 + eventString2 + ")");
		}

		static EventType GetStaticType() { return EventType::KeyPressed; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "KeyPressed"; }

	private:
		bool m_IsRepeat;
	};



	class KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(const KeyCode keyCode) : KeyEvent(keyCode) {}

		std::string ToString() {
			std::string eventString = "KeyReleasedEvent: " + m_KeyCode;
			return eventString;
		}

		static EventType GetStaticType() { return EventType::KeyReleased; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "KeyReleased"; }
	};



	class KeyTypedEvent : KeyEvent {
	public:
		KeyTypedEvent(const KeyCode keyCode) : KeyEvent(keyCode) {}

		std::string ToString() const override {
			std::string eventString = "KeyTypedEvent: " + m_KeyCode;
			return eventString;
		}

		static EventType GetStaticType() { return EventType::KeyTyped; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "KeyTyped"; }
	};
}
