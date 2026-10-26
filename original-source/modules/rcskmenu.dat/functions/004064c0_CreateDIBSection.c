/*
 * GDI32.DLL::CreateDIBSection at 004064c0
 * HBITMAP __stdcall CreateDIBSection(HDC hdc, BITMAPINFO * lpbmi, UINT usage, void * * ppvBits, HANDLE hSection, DWORD offset)
 * Address ranges: 004064c0-004064c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::CreateDIBSection
 */

HBITMAP __stdcall
CreateDIBSection(HDC hdc,BITMAPINFO *lpbmi,UINT usage,void **ppvBits,HANDLE hSection,DWORD offset)

{
  HBITMAP pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004064c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = CreateDIBSection(hdc,lpbmi,usage,ppvBits,hSection,offset);
  return pHVar1;
}

