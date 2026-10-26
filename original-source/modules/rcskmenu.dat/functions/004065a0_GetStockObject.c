/*
 * GDI32.DLL::GetStockObject at 004065a0
 * HGDIOBJ __stdcall GetStockObject(int i)
 * Address ranges: 004065a0-004065a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::GetStockObject
 */

HGDIOBJ __stdcall GetStockObject(int i)

{
  HGDIOBJ pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004065a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = GetStockObject(i);
  return pvVar1;
}

