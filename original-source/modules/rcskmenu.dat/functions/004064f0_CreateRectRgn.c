/*
 * GDI32.DLL::CreateRectRgn at 004064f0
 * HRGN __stdcall CreateRectRgn(int x1, int y1, int x2, int y2)
 * Address ranges: 004064f0-004064f5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::CreateRectRgn
 */

HRGN __stdcall CreateRectRgn(int x1,int y1,int x2,int y2)

{
  HRGN pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004064f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = CreateRectRgn(x1,y1,x2,y2);
  return pHVar1;
}

