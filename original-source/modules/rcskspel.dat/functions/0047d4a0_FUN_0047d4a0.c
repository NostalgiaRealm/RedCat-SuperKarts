/*
 * FUN_0047d4a0 at 0047d4a0
 * undefined FUN_0047d4a0(void)
 * Address ranges: 0047d4a0-0047d5fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0047d4e9) */

undefined4 * __thiscall
FUN_0047d4a0(undefined4 *param_1,undefined4 *param_2,undefined1 *param_3,undefined4 param_4)

{
  undefined1 uVar1;
  uint uVar2;
  char cVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d1086;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)param_2;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  uVar2 = param_2[2];
  if (param_1 + 1 == param_2) {
    FUN_004478a0(uVar2,0xffffffff);
    FUN_004478a0(0,0);
  }
  else {
    if (uVar2 != 0) {
      puVar4 = (undefined1 *)param_2[1];
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      if ((byte)puVar4[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar4 = (undefined1 *)param_2[1];
        if (puVar4 == (undefined1 *)0x0) {
          puVar4 = &DAT_004d2404;
        }
        param_1[2] = puVar4;
        param_1[3] = param_2[2];
        param_1[4] = param_2[3];
        puVar4[-1] = puVar4[-1] + '\x01';
        goto LAB_0047d591;
      }
    }
    cVar3 = FUN_0040b600(uVar2,1);
    if (cVar3 != '\0') {
      puVar6 = (undefined4 *)param_2[1];
      if (puVar6 == (undefined4 *)0x0) {
        puVar6 = (undefined4 *)&DAT_004d2404;
      }
      puVar7 = (undefined4 *)param_1[2];
      for (uVar5 = uVar2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      for (uVar5 = uVar2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      FUN_0040b5e0(uVar2);
    }
  }
LAB_0047d591:
  local_4 = 0;
  uVar1 = *param_3;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 5) = uVar1;
  param_1[7] = 0;
  param_1[8] = 0;
  FUN_00412870(param_3,0,0xffffffff);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_004777e0(param_4);
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  *param_1 = &PTR_FUN_004d2e64;
  ExceptionList = local_c;
  return param_1;
}

