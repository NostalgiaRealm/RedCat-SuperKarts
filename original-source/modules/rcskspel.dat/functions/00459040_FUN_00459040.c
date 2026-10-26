/*
 * FUN_00459040 at 00459040
 * undefined FUN_00459040(void)
 * Address ranges: 00459040-0045916f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * FUN_00459040(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 local_1c [4];
  int local_18;
  int local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cdfa8;
  pvStack_c = ExceptionList;
  local_1c[0] = *param_2;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  ExceptionList = &pvStack_c;
  FUN_00412870(param_2,0,0xffffffff);
  local_4 = 0;
  uVar4 = 0xffffffff;
  if (*(uint *)(param_3 + 8) != 0xffffffff) {
    uVar4 = *(uint *)(param_3 + 8);
  }
  if (-local_14 - 1U <= uVar4) {
    FUN_004bc15b();
  }
  if (uVar4 != 0) {
    iVar1 = local_14 + uVar4;
    cVar2 = FUN_0040b600(iVar1,0);
    if (cVar2 != '\0') {
      puVar5 = *(undefined4 **)(param_3 + 4);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)&DAT_004d2404;
      }
      puVar6 = (undefined4 *)(local_14 + local_18);
      for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      *(undefined1 *)(local_18 + iVar1) = 0;
      local_14 = iVar1;
    }
  }
  *param_1 = local_1c[0];
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  FUN_00412870(local_1c,0,0xffffffff);
  if (local_18 != 0) {
    cVar2 = *(char *)(local_18 + -1);
    if ((cVar2 != '\0') && (cVar2 != -1)) {
      *(char *)(local_18 + -1) = cVar2 + -1;
      ExceptionList = pvStack_c;
      return param_1;
    }
    FUN_004bc150((char *)(local_18 + -1));
  }
  ExceptionList = pvStack_c;
  return param_1;
}

