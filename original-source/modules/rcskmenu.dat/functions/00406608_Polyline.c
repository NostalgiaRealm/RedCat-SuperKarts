/*
 * GDI32.DLL::Polyline at 00406608
 * BOOL __stdcall Polyline(HDC hdc, POINT * apt, int cpt)
 * Address ranges: 00406608-0040660d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::Polyline
 */

BOOL __stdcall Polyline(HDC hdc,POINT *apt,int cpt)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406608. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = Polyline(hdc,apt,cpt);
  return BVar1;
}

