#include "Header.hpp"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	DWORD dwIsApplication;

	try
	{
		if (!LaunchedAsApplication(&dwIsApplication))
			throw NULL; // Here i just need to get out of try{}, please help me how to improve this

		if (!dwIsApplication)
		{
			SERVICE_TABLE_ENTRY DispatchTable;

			DispatchTable.lpServiceName = (LPWSTR)SERVICE_INSTALL_NAME;
			DispatchTable.lpServiceProc = (LPSERVICE_MAIN_FUNCTION)SvcMain;

			// This call returns when the service has stopped. 
			// The process should simply terminate when the call returns.

			if (!StartServiceCtrlDispatcher(&DispatchTable))
			{
				SvcReportEvent((LPTSTR)"StartServiceCtrlDispatcher");
			}

			return EXIT_SUCCESS;
		}

		Log("Bootstrapper started");

		StartupSvc();
	}
	catch (...) {}

	return EXIT_SUCCESS;
}
