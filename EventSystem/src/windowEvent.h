#pragma once
#include "event.h"
namespace CoreNative
{
	class WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent()
			:
			Event("Window Closed Event", EventType::WINDOW_CLOSED_EVENT){}
	public:
		std::string format() const override
		{
			return name;
		}
	};
}