/*
 * FUN_0049d5e0 at 0049d5e0
 * undefined FUN_0049d5e0(void)
 * Address ranges: 0049d5e0-0049d649
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0049d5e0(int param_1,int param_2)

{
  int iVar1;
  int local_4;
  
  local_4 = param_1;
  iVar1 = FUN_0049d870();
  if (iVar1 != 0) {
    local_4 = (*(int *)(param_1 + 0x3c) * param_2) / 100 + *(int *)(param_1 + 0x3c);
    FUN_0049f340(&local_4,100,100000);
    FUN_004b47c0(*(undefined4 *)(param_1 + 0x38),local_4);
    *(int *)(param_1 + 0x4c) = param_2;
    return;
  }
  *(int *)(param_1 + 0x4c) = param_2;
  return;
}

