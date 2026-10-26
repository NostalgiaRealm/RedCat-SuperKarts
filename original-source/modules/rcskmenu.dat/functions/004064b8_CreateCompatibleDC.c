/*
 * GDI32.DLL::CreateCompatibleDC at 004064b8
 * HDC __stdcall CreateCompatibleDC(HDC hdc)
 * Address ranges: 004064b8-004064bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::CreateCompatibleDC
 */

HDC __stdcall CreateCompatibleDC(HDC hdc)

{
  HDC pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004064b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = CreateCompatibleDC(hdc);
  return pHVar1;
}

