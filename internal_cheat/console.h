    #pragma once

	void CreateConsole();
    void ReleaseConsole();
    bool ConsolePrint(const char* fmt, ...);
    bool ConsolePrintW(const wchar_t* fmt, ...);