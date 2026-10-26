/*
 * GDI32.DLL::GdiFlush at 00406528
 * BOOL __stdcall GdiFlush(void)
 * Address ranges: 00406528-0040652d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::GdiFlush
 */

BOOL __stdcall GdiFlush(void)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406528. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GdiFlush();
  return BVar1;
}

