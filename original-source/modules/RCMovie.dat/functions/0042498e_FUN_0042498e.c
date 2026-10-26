/*
 * FUN_0042498e at 0042498e
 * int __cdecl FUN_0042498e(int param_1)
 * Address ranges: 0042498e-004249d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_0042498e(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_0043e470 = 1;
                    /* WARNING: Could not recover jumptable at 0x004249a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_0043e470 = 1;
                    /* WARNING: Could not recover jumptable at 0x004249bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_0043e598;
  }
  DAT_0043e470 = (uint)bVar2;
  return param_1;
}

