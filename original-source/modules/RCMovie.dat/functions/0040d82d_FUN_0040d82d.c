/*
 * FUN_0040d82d at 0040d82d
 * undefined4 __stdcall FUN_0040d82d(void)
 * Address ranges: 0040d82d-0040d899
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040d82d(void)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (9 < local_8) {
      return 0;
    }
    if ((*(int *)(&DAT_004322f0 + local_8 * 4) != -1) &&
       (iVar1 = FUN_004133f0(*(uint *)(&DAT_004322f0 + local_8 * 4)), iVar1 != 0)) break;
    local_8 = local_8 + 1;
  }
  while (iVar1 = FUN_004133f0(*(uint *)(&DAT_004322f0 + local_8 * 4)), iVar1 != 0) {
    FUN_0040a97d();
  }
  return 1;
}

