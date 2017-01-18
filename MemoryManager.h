#include <iostream>
#include <Windows.h>

class MemoryManager
{
	public:
		MemoryManager();
		int attach(const DWORD& procId);
		int attach(const std::string& windowName);
		int attach(std::string processName);
		void detach();

	private:
		HANDLE m_processHandle;
		HWND m_processHWND;
		DWORD m_processId;
		bool m_attached;
};