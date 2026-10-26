/*
 * FUN_004bccd4 at 004bccd4
 * undefined FUN_004bccd4(void)
 * Address ranges: 004bccd4-004bcd55
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004bccd4(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_24 [6];
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x50) != 0) {
    iVar1 = FUN_004c0331(*(int *)(param_1 + 0x50),param_3,param_4);
    if (iVar1 == 0) {
      iVar1 = FUN_004c1290(*(undefined4 *)(param_1 + 0x50),&local_c);
      if (iVar1 == 0) {
        local_24[0] = 0;
        local_24[2] = local_c;
        local_24[3] = local_8;
        local_24[4] = *(undefined4 *)(param_1 + 0x40);
        goto LAB_004bcd49;
      }
    }
  }
  local_24[0] = 0xffffffff;
  local_24[2] = 0;
  local_24[3] = 0;
  local_24[4] = DAT_006b6a54;
LAB_004bcd49:
  puVar2 = local_24;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_2 = *puVar2;
    puVar2 = puVar2 + 1;
    param_2 = param_2 + 1;
  }
  return;
}

