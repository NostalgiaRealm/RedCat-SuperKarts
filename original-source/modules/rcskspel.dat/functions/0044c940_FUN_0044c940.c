/*
 * FUN_0044c940 at 0044c940
 * undefined FUN_0044c940(void)
 * Address ranges: 0044c940-0044ca73
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall FUN_0044c940(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd971;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  param_1[6] = param_2[6];
  *(undefined1 *)(param_1 + 7) = *(undefined1 *)(param_2 + 7);
  *(undefined1 *)(param_1 + 8) = *(undefined1 *)(param_2 + 8);
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  FUN_00412870(param_2 + 8,0,0xffffffff);
  local_4 = 0;
  *(undefined1 *)(param_1 + 0xc) = *(undefined1 *)(param_2 + 0xc);
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  FUN_00412870(param_2 + 0xc,0,0xffffffff);
  local_4._0_1_ = 1;
  *(undefined1 *)(param_1 + 0x10) = *(undefined1 *)(param_2 + 0x10);
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  FUN_00412870(param_2 + 0x10,0,0xffffffff);
  local_4 = CONCAT31(local_4._1_3_,2);
  *(undefined1 *)(param_1 + 0x14) = *(undefined1 *)(param_2 + 0x14);
  if (param_2[0x15] == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (int)(param_2[0x16] - param_2[0x15]) >> 2;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  puVar2 = operator_new(iVar3 * 4);
  param_1[0x15] = puVar2;
  puVar1 = (undefined4 *)param_2[0x16];
  for (puVar4 = (undefined4 *)param_2[0x15]; puVar4 != puVar1; puVar4 = puVar4 + 1) {
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = *puVar4;
    }
    puVar2 = puVar2 + 1;
  }
  param_1[0x16] = puVar2;
  param_1[0x17] = puVar2;
  ExceptionList = local_c;
  return param_1;
}

