/*
 * FUN_00404fde at 00404fde
 * int __cdecl FUN_00404fde(int param_1)
 * Address ranges: 00404fde-00405027
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00404fde(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_00408d7c = 1;
                    /* WARNING: Could not recover jumptable at 0x00404ff8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_00408d7c = 1;
                    /* WARNING: Could not recover jumptable at 0x0040500d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_00408da8;
  }
  DAT_00408d7c = (uint)bVar2;
  return param_1;
}

