/*
 * GDI32.DLL::GetDCOrgEx at 00406550
 * BOOL __stdcall GetDCOrgEx(HDC hdc, LPPOINT lppt)
 * Address ranges: 00406550-00406555
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::GetDCOrgEx
 */

BOOL __stdcall GetDCOrgEx(HDC hdc,LPPOINT lppt)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetDCOrgEx(hdc,lppt);
  return BVar1;
}

