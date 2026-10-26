/*
 * FUN_00477060 at 00477060
 * undefined FUN_00477060(void)
 * Address ranges: 00477060-004771aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x004770d9) */

void FUN_00477060(undefined1 *param_1,undefined1 *param_2)

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
  
  puStack_8 = &LAB_004d0c09;
  local_c = ExceptionList;
  local_4 = 0;
  if (param_1 != (undefined1 *)0x0) {
    uVar1 = *param_2;
    ExceptionList = &local_c;
    *(undefined4 *)(param_1 + 4) = 0;
    *param_1 = uVar1;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    FUN_00412870(param_2,0,0xffffffff);
    local_4 = CONCAT31(local_4._1_3_,1);
    param_1[0x10] = param_2[0x10];
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    uVar2 = *(uint *)(param_2 + 0x18);
    if (param_1 + 0x10 == param_2 + 0x10) {
      FUN_004478a0(uVar2,0xffffffff);
      FUN_004478a0(0,0);
      ExceptionList = local_c;
      return;
    }
    if (uVar2 != 0) {
      puVar4 = *(undefined1 **)(param_2 + 0x14);
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      if ((byte)puVar4[-1] < 0xfe) {
        *(undefined4 *)(param_1 + 0x14) = 0;
        *(undefined4 *)(param_1 + 0x18) = 0;
        *(undefined4 *)(param_1 + 0x1c) = 0;
        puVar4 = *(undefined1 **)(param_2 + 0x14);
        if (puVar4 == (undefined1 *)0x0) {
          puVar4 = &DAT_004d2404;
        }
        *(undefined1 **)(param_1 + 0x14) = puVar4;
        *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 0x18);
        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
        puVar4[-1] = puVar4[-1] + '\x01';
        ExceptionList = local_c;
        return;
      }
    }
    cVar3 = FUN_0040b600(uVar2,1);
    if (cVar3 != '\0') {
      puVar6 = (undefined4 *)&DAT_004d2404;
      if (*(undefined4 **)(param_2 + 0x14) != (undefined4 *)0x0) {
        puVar6 = *(undefined4 **)(param_2 + 0x14);
      }
      puVar7 = *(undefined4 **)(param_1 + 0x14);
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
  ExceptionList = local_c;
  return;
}

