/*
 * GDI32.DLL::SetWindowOrgEx at 004066a0
 * BOOL __stdcall SetWindowOrgEx(HDC hdc, int x, int y, LPPOINT lppt)
 * Address ranges: 004066a0-004066a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::SetWindowOrgEx
 */

BOOL __stdcall SetWindowOrgEx(HDC hdc,int x,int y,LPPOINT lppt)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004066a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = SetWindowOrgEx(hdc,x,y,lppt);
  return BVar1;
}

