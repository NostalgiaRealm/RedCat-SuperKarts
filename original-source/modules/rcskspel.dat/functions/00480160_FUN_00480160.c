/*
 * FUN_00480160 at 00480160
 * undefined FUN_00480160(void)
 * Address ranges: 00480160-004802b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00480160(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  void **ppvVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 **ppuVar6;
  undefined4 *puVar7;
  bool bVar8;
  undefined4 *puVar9;
  undefined1 local_29;
  undefined4 *local_28;
  undefined1 local_24 [4];
  undefined4 local_20;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar1 = param_3;
  puStack_8 = &LAB_004d1288;
  local_c = ExceptionList;
  puVar5 = *(undefined4 **)(param_1 + 4);
  bVar8 = true;
  puVar7 = (undefined4 *)puVar5[1];
  local_4 = 0;
  ExceptionList = &local_c;
  ppvVar2 = &local_c;
  if (puVar7 != DAT_00544fb0) {
    do {
      puVar5 = puVar7;
      puVar3 = (undefined1 *)puVar5[4];
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_004d2404;
      }
      iVar4 = FUN_00460440(0,*(undefined4 *)(iVar1 + 8),puVar3,puVar5[5]);
      bVar8 = iVar4 < 0;
      if (bVar8) {
        puVar7 = (undefined4 *)*puVar5;
      }
      else {
        puVar7 = (undefined4 *)puVar5[2];
      }
      ppvVar2 = ExceptionList;
    } while (puVar7 != DAT_00544fb0);
  }
  ExceptionList = ppvVar2;
  local_4 = 0xffffffff;
  if (*(char *)(param_1 + 8) == '\0') {
    local_28 = puVar5;
    if (bVar8) {
      if (puVar5 == (undefined4 *)**(int **)(param_1 + 4)) {
        puVar5 = (undefined4 *)FUN_00480420(&param_3,puVar7,puVar5,iVar1);
        local_20 = CONCAT31(local_20._1_3_,1);
        *param_2 = *puVar5;
        param_2[1] = local_20;
        ExceptionList = local_c;
        return;
      }
      FUN_00480a50();
    }
    iVar4 = FUN_0045aab0(iVar1);
    if (iVar4 < 0) {
      puVar9 = &param_3;
      param_3 = CONCAT31(param_3._1_3_,1);
      ppuVar6 = (undefined4 **)FUN_00480420(local_24,puVar7,puVar5,iVar1);
    }
    else {
      puVar9 = (undefined4 *)&local_29;
      ppuVar6 = &local_28;
      local_29 = 0;
    }
    puVar5 = (undefined4 *)FUN_00480350(ppuVar6,puVar9);
    *param_2 = *puVar5;
    param_2[1] = puVar5[1];
  }
  else {
    puVar5 = (undefined4 *)FUN_00480420(&param_3,puVar7,puVar5,iVar1);
    local_20 = CONCAT31(local_20._1_3_,1);
    *param_2 = *puVar5;
    param_2[1] = local_20;
  }
  ExceptionList = local_c;
  return;
}

