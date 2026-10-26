/*
 * FUN_00459dc0 at 00459dc0
 * undefined FUN_00459dc0(void)
 * Address ranges: 00459dc0-00459f39
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00459e1c) */

undefined4 * __thiscall FUN_00459dc0(undefined4 *param_1,undefined4 *param_2)

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
  puStack_8 = &LAB_004ce103;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004bfd82();
  *(undefined1 *)(param_1 + 3) = param_2._0_1_;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *param_1 = &PTR_FUN_004d2888;
  local_4 = 1;
  uVar1 = param_2[2];
  if (param_1 + 3 == param_2) {
    if ((uint)param_1[5] < uVar1) {
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
      puVar4 = (undefined1 *)param_2[1];
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      if ((byte)puVar4[-1] < 0xfe) {
        iVar6 = param_1[4];
        if (iVar6 != 0) {
          cVar2 = *(char *)(iVar6 + -1);
          if ((cVar2 == '\0') || (cVar2 == -1)) {
            FUN_004bc150((char *)(iVar6 + -1));
          }
          else {
            *(char *)(iVar6 + -1) = cVar2 + -1;
          }
        }
        param_1[4] = 0;
        param_1[5] = 0;
        param_1[6] = 0;
        puVar4 = (undefined1 *)param_2[1];
        if (puVar4 == (undefined1 *)0x0) {
          puVar4 = &DAT_004d2404;
        }
        param_1[4] = puVar4;
        param_1[5] = param_2[2];
        param_1[6] = param_2[3];
        puVar4[-1] = puVar4[-1] + '\x01';
        ExceptionList = local_c;
        return param_1;
      }
    }
    cVar2 = FUN_0040b600(uVar1,1);
    if (cVar2 != '\0') {
      puVar7 = (undefined4 *)param_2[1];
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
      FUN_0040b5e0(uVar1);
    }
  }
  ExceptionList = local_c;
  return param_1;
}

