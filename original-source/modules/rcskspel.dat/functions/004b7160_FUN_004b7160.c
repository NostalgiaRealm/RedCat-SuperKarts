/*
 * FUN_004b7160 at 004b7160
 * undefined FUN_004b7160(void)
 * Address ranges: 004b7160-004b71ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b7160(int param_1)

{
  if (DAT_006ab868 != param_1) {
    DAT_006ab868 = param_1;
    if (param_1 != 0) {
      DAT_006ab864 = 1;
      _DAT_006ab85c = *(undefined4 *)(param_1 + 0x8c);
      _DAT_006ab860 = *(undefined4 *)(param_1 + 0x88);
      return;
    }
    DAT_006ab864 = 0;
    _DAT_006ab85c = 0;
    _DAT_006ab860 = 0;
  }
  return;
}

