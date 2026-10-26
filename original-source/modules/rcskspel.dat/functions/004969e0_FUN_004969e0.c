/*
 * FUN_004969e0 at 004969e0
 * undefined FUN_004969e0(void)
 * Address ranges: 004969e0-00496a59
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004969e0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (*(int *)(param_1 + 0x9a) == 0) {
    param_2[6] = ABS((float)param_2[6]) * _DAT_006a5ed0 +
                 *(float *)(DAT_006a5e80 + 0x34 + *(int *)(param_1 + 0x56) * 0x48);
    param_2[7] = ABS((float)param_2[7]) * _DAT_006a5ed4 +
                 *(float *)(DAT_006a5e80 + 0x38 + *(int *)(param_1 + 0x56) * 0x48);
  }
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0x92) * 0x20 + *(int *)(param_1 + 0x8a));
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  *(int *)(param_1 + 0x92) = *(int *)(param_1 + 0x92) + 1;
  return;
}

