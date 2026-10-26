/*
 * FUN_00443d20 at 00443d20
 * undefined FUN_00443d20(void)
 * Address ranges: 00443d20-00443da8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00443d20(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_20 [5];
  undefined4 local_c;
  int local_8;
  undefined1 local_4;
  undefined1 local_3;
  
  local_20[0]._0_1_ = 1;
  local_c = DAT_00508638;
  local_20[3] = 0x3f000000;
  local_20[4] = *(undefined4 *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20);
  local_8 = param_2;
  local_4 = 0;
  local_3 = 0;
  *(int *)(&DAT_0053f670 + param_2 * 0x340) = *(int *)(&DAT_0053f670 + param_2 * 0x340) + 1000;
  FUN_00445740(local_20);
  puVar2 = local_20;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

