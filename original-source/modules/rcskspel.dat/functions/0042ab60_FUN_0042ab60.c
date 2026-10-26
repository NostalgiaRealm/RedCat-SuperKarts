/*
 * FUN_0042ab60 at 0042ab60
 * undefined FUN_0042ab60(void)
 * Address ranges: 0042ab60-0042ab7d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0042ab60(int param_1,int param_2)

{
  if ((0 < param_2) && (param_2 < 0x1f)) {
    *(int *)(param_1 + 0x10) = param_2;
    return;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

