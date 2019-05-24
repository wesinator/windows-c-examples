// https://docs.microsoft.com/en-us/windows/desktop/api/winbase/nf-winbase-localalloc#examples

#include <windows.h>
#include <stdio.h>
#include <tchar.h>

void _cdecl _tmain()
{
    LPTSTR pszBuf=NULL;

    pszBuf = (LPTSTR)LocalAlloc(
              LPTR,
              MAX_PATH*sizeof(TCHAR));

    // Handle error condition
    if( pszBuf == NULL )
    {
       _tprintf(TEXT("LocalAlloc failed (%d)\n"), GetLastError());
       return;
    }

    //see how much memory was allocated
    _tprintf(TEXT("LocalAlloc allocated %d bytes\n"), LocalSize(pszBuf));

    // Use the memory allocated

    // Free the memory when finished with it
    LocalFree(pszBuf);
}
