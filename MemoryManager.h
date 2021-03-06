#include <iostream>
#include <Windows.h>

namespace MemManager
{
    class MemoryManager
    {
	public:
	    MemoryManager();
	    int attach(const DWORD& procId);
            int attach(const std::string& windowName);
	    void detach();

	private:
	    HANDLE m_processHandle;
	    HWND m_processHWND;
	    DWORD m_processId;
	    bool m_attached;
    };
	
    DWORD FindProcessId(const std::string& processName);	
}	
