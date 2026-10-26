/*
 * GDI32.DLL::MoveToEx at 004065f0
 * BOOL __stdcall MoveToEx(HDC hdc, int x, int y, LPPOINT lppt)
 * Address ranges: 004065f0-004065f5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::MoveToEx
 */

BOOL __stdcall MoveToEx(HDC hdc,int x,int y,LPPOINT lppt)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004065f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = MoveToEx(hdc,x,y,lppt);
  return BVar1;
}

