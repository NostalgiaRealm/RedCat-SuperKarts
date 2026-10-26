/*
 * FUN_00445c70 at 00445c70
 * undefined FUN_00445c70(void)
 * Address ranges: 00445c70-00445d9d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00445cb2) */

undefined1 * __thiscall
FUN_00445c70(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_004cd682;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = *param_2;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  uVar2 = *(uint *)(param_2 + 8);
  if (param_1 == param_2) {
    FUN_004478a0(uVar2,0xffffffff);
    FUN_004478a0(0,0);
  }
  else {
    if (uVar2 != 0) {
      puVar4 = *(undefined1 **)(param_2 + 4);
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      if ((byte)puVar4[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar4 = *(undefined1 **)(param_2 + 4);
        if (puVar4 == (undefined1 *)0x0) {
          puVar4 = &DAT_004d2404;
        }
        *(undefined1 **)(param_1 + 4) = puVar4;
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
        puVar4[-1] = puVar4[-1] + '\x01';
        goto LAB_00445d4b;
      }
    }
    cVar3 = FUN_0040b600(uVar2,1);
    if (cVar3 != '\0') {
      puVar6 = *(undefined4 **)(param_2 + 4);
      if (puVar6 == (undefined4 *)0x0) {
        puVar6 = (undefined4 *)&DAT_004d2404;
      }
      puVar7 = *(undefined4 **)(param_1 + 4);
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
LAB_00445d4b:
  local_4 = 0;
  uVar1 = *param_3;
  *(undefined4 *)(param_1 + 0x14) = 0;
  param_1[0x10] = uVar1;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  FUN_00412870(param_3,0,0xffffffff);
  *(undefined4 *)(param_1 + 0x20) = param_4;
  *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  ExceptionList = local_c;
  return param_1;
}

