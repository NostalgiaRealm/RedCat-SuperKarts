/*
 * FUN_004503e0 at 004503e0
 * undefined FUN_004503e0(void)
 * Address ranges: 004503e0-0045043c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004503e0(int param_1,char param_2)

{
  FUN_00450440();
  if (*(int *)(param_1 + 0xc) == -1) {
    *(bool *)(DAT_006a5c38 + *(int *)(param_1 + 8) * 0xa9 + 0x90) = param_2 != '\0';
    return;
  }
  *(uint *)(*(int *)(param_1 + 0xc) * 0xd0 + 0x44 + DAT_0067ee20) = (uint)(param_2 != '\0');
  return;
}

