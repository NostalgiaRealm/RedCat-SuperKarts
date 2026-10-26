/*
 * GDI32.DLL::SetViewportOrgEx at 00406690
 * BOOL __stdcall SetViewportOrgEx(HDC hdc, int x, int y, LPPOINT lppt)
 * Address ranges: 00406690-00406695
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::SetViewportOrgEx
 */

BOOL __stdcall SetViewportOrgEx(HDC hdc,int x,int y,LPPOINT lppt)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406690. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = SetViewportOrgEx(hdc,x,y,lppt);
  return BVar1;
}

