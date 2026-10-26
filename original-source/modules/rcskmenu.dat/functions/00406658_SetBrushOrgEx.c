/*
 * GDI32.DLL::SetBrushOrgEx at 00406658
 * BOOL __stdcall SetBrushOrgEx(HDC hdc, int x, int y, LPPOINT lppt)
 * Address ranges: 00406658-0040665d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::SetBrushOrgEx
 */

BOOL __stdcall SetBrushOrgEx(HDC hdc,int x,int y,LPPOINT lppt)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406658. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = SetBrushOrgEx(hdc,x,y,lppt);
  return BVar1;
}

