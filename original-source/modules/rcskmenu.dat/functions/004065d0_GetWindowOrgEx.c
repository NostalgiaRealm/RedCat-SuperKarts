/*
 * GDI32.DLL::GetWindowOrgEx at 004065d0
 * BOOL __stdcall GetWindowOrgEx(HDC hdc, LPPOINT lppoint)
 * Address ranges: 004065d0-004065d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::GetWindowOrgEx
 */

BOOL __stdcall GetWindowOrgEx(HDC hdc,LPPOINT lppoint)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004065d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetWindowOrgEx(hdc,lppoint);
  return BVar1;
}

