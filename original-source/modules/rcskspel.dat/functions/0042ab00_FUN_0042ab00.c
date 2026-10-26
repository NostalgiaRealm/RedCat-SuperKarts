/*
 * FUN_0042ab00 at 0042ab00
 * undefined FUN_0042ab00(void)
 * Address ranges: 0042ab00-0042ab2e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0042ab00(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < 10)) {
    *(int *)(param_1 + 8) = param_2;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 4) + *(int *)(param_1 + 8);
    return;
  }
  *(undefined4 *)(param_1 + 8) = 1;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 4) + *(int *)(param_1 + 8);
  return;
}

