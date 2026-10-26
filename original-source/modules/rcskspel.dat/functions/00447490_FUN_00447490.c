/*
 * FUN_00447490 at 00447490
 * undefined FUN_00447490(void)
 * Address ranges: 00447490-004475ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x004474e4) */

undefined4 * __thiscall FUN_00447490(undefined4 *param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd748;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004bfdec(param_2);
  local_4 = 0;
  *(undefined1 *)(param_1 + 3) = *(undefined1 *)(param_2 + 0xc);
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  uVar1 = *(uint *)(param_2 + 0x14);
  if (param_1 + 3 == (undefined4 *)(param_2 + 0xc)) {
    if (uVar1 != 0) {
      FUN_004bc243();
    }
    FUN_00412a80();
    iVar3 = param_1[5] - uVar1;
    iVar6 = -1;
    if (iVar3 != -1) {
      iVar6 = iVar3;
    }
    if (iVar6 != 0) {
      FUN_004bef90(uVar1 + param_1[4],uVar1 + param_1[4] + iVar6,iVar3 - iVar6);
      iVar3 = param_1[5];
      cVar2 = FUN_0040b600(iVar3 - iVar6,0);
      if (cVar2 != '\0') {
        FUN_0040b5e0(iVar3 - iVar6);
      }
    }
    FUN_00412a80();
  }
  else {
    if (uVar1 != 0) {
      puVar4 = *(undefined1 **)(param_2 + 0x10);
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      if ((byte)puVar4[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar4 = *(undefined1 **)(param_2 + 0x10);
        if (puVar4 == (undefined1 *)0x0) {
          puVar4 = &DAT_004d2404;
        }
        param_1[4] = puVar4;
        param_1[5] = *(undefined4 *)(param_2 + 0x14);
        param_1[6] = *(undefined4 *)(param_2 + 0x18);
        puVar4[-1] = puVar4[-1] + '\x01';
        goto LAB_00447542;
      }
    }
    cVar2 = FUN_0040b600(uVar1,1);
    if (cVar2 != '\0') {
      puVar7 = *(undefined4 **)(param_2 + 0x10);
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)&DAT_004d2404;
      }
      puVar8 = (undefined4 *)param_1[4];
      for (uVar5 = uVar1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      for (uVar5 = uVar1 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      param_1[5] = uVar1;
      *(undefined1 *)(param_1[4] + uVar1) = 0;
      *param_1 = &PTR_FUN_004d34f4;
      ExceptionList = local_c;
      return param_1;
    }
  }
LAB_00447542:
  *param_1 = &PTR_FUN_004d34f4;
  ExceptionList = local_c;
  return param_1;
}

