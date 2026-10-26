/*
 * FUN_00496940 at 00496940
 * undefined FUN_00496940(void)
 * Address ranges: 00496940-004969ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00496940(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (*(int *)(param_1 + 0x9a) == 0) {
    param_2[6] = ABS((float)param_2[6]) * _DAT_006a5ed0 +
                 *(float *)(DAT_006a5e80 + 0x34 + *(int *)(param_1 + 0x52) * 0x48);
    param_2[7] = ABS((float)param_2[7]) * _DAT_006a5ed4 +
                 *(float *)(DAT_006a5e80 + 0x38 + *(int *)(param_1 + 0x52) * 0x48);
  }
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0x62) * 0x20 + *(int *)(param_1 + 0x5a));
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  *(int *)(param_1 + 0x62) = *(int *)(param_1 + 0x62) + 1;
  return;
}

