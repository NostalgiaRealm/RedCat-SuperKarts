/*
 * FUN_004c7099 at 004c7099
 * undefined FUN_004c7099(void)
 * Address ranges: 004c7099-004c70e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004c7099(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_006b67c4 = 1;
                    /* WARNING: Could not recover jumptable at 0x004c70b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_006b67c4 = 1;
                    /* WARNING: Could not recover jumptable at 0x004c70c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_006b675c;
  }
  DAT_006b67c4 = (uint)bVar2;
  return param_1;
}

