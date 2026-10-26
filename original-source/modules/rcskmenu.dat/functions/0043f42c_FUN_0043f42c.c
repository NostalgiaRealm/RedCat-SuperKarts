/*
 * FUN_0043f42c at 0043f42c
 * undefined FUN_0043f42c(void)
 * Address ranges: 0043f42c-0043f4c1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f42c(int *param_1,uint *param_2)

{
  int *piVar1;
  bool bVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar5;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  uint *puStack_c;
  uint *puStack_8;
  
  puStack_1c = &stack0xfffffffc;
  puStack_c = (uint *)0x0;
  puStack_20 = &LAB_0043f4c2;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  puVar3 = &stack0xfffffffc;
  puStack_8 = param_2;
  if (((*(byte *)(param_1 + 0x10) & 0x20) != 0) &&
     (uVar5 = (*(byte *)(param_1 + 8) & 1) == 0, puVar3 = &stack0xfffffffc, (bool)uVar5)) {
    FUN_0043f64c((int)param_1,(int *)&puStack_c);
    FUN_00403ee0((uint *)param_1[2],puStack_c);
    puVar3 = puStack_1c;
    if ((bool)uVar5) {
      piVar1 = (int *)param_1[1];
      if (piVar1 != (int *)0x0) {
        uVar4 = FUN_00403024(piVar1,(int)&PTR_FUN_0043b888);
        if (((char)uVar4 != '\0') && (puVar3 = puStack_1c, (*(byte *)(piVar1 + 8) & 1) != 0))
        goto LAB_0043f48e;
      }
      bVar2 = true;
      goto LAB_0043f494;
    }
  }
LAB_0043f48e:
  puStack_1c = puVar3;
  bVar2 = false;
LAB_0043f494:
  FUN_00414cdc(param_1,puStack_8);
  if (bVar2) {
    FUN_0043f67c((int)param_1,puStack_8);
  }
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_0043f4c9;
  puStack_20 = (undefined1 *)0x43f4c1;
  FUN_00403b50((int *)&puStack_c);
  return;
}

