#include "MemoryManager.h"

namespace MemManager
{
	int MemoryManager::attach(const DWORD& procId)
	{
		if (procId == 0)
		{
			return -1;
		}

		m_processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procId);

		if (m_processHandle == NULL)
		{
			return -1;
		}

		return 0;
	}

	int MemoryManager::attach(const std::string& windowName)
	{
		m_processHWND = FindWindowA(0, windowName.c_str());

		if (m_processHWND == NULL)
		{
			return -1;
		}

		GetWindowThreadProcessId(m_processHWND, &m_)


	//Todo finish this function
	}

	void MemoryManager::detach()
	{
		CloseHandle(m_processHandle);
	}
	
	WORD FindProcessId(const std::string& processName)
	{
	    PROCESSENTRY32 processInfo;
	    processInfo.dwSize = sizeof(processInfo);

	    HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
		
	    if (processesSnapshot == INVALID_HANDLE_VALUE)
		return 0;

	    Process32First(processesSnapshot, &processInfo);
		
	    if (!processName.compare(processInfo.szExeFile))
	    {
		CloseHandle(processesSnapshot);
		return processInfo.th32ProcessID;
	    }

	    while (Process32Next(processesSnapshot, &processInfo))
	    {
		if (!processName.compare(processInfo.szExeFile))
		{
		    CloseHandle(processesSnapshot);
		    return processInfo.th32ProcessID;
		}
	    }

	    CloseHandle(processesSnapshot);
	    return 0;
    }	
}	
