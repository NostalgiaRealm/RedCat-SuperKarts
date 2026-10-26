/*
 * FUN_004765d0 at 004765d0
 * undefined FUN_004765d0(void)
 * Address ranges: 004765d0-0047678e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * FUN_004765d0(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 *puVar8;
  undefined1 local_4c [4];
  undefined4 *local_48;
  undefined1 local_3c [4];
  undefined1 *local_38;
  undefined1 local_2c [16];
  undefined1 local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0bdc;
  local_c = ExceptionList;
  local_3c[0] = (undefined1)param_3;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  local_4c[0] = (undefined1)param_3;
  local_4 = 0;
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar7 = (char *)&DAT_004f7d54;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4 - 1;
  cVar1 = FUN_0040b600(uVar4,1);
  if (cVar1 != '\0') {
    puVar6 = &DAT_004f7d54;
    puVar8 = local_48;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    FUN_0040b5e0(uVar4);
  }
  local_4._0_1_ = 1;
  FUN_00476580(param_3);
  uVar2 = FUN_00474f90();
  FUN_00476510(param_2);
  uVar2 = FUN_00475100(uVar2);
  uVar2 = FUN_00459040(local_1c,uVar2);
  local_4._0_1_ = 2;
  uVar2 = FUN_00459040(local_2c,uVar2,local_4c);
  local_4._0_1_ = 3;
  FUN_00412870(uVar2,0,0xffffffff);
  local_4._0_1_ = 2;
  FUN_0040b4f0(1);
  local_4._0_1_ = 1;
  FUN_0040b4f0(1);
  local_4 = (uint)local_4._1_3_ << 8;
  if (local_48 != (undefined4 *)0x0) {
    cVar1 = *(char *)((int)local_48 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)((int)local_48 + -1));
    }
    else {
      *(char *)((int)local_48 + -1) = cVar1 + -1;
    }
  }
  puVar3 = local_38;
  if (local_38 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  FUN_004afce0(s____________s_004f7d5c,puVar3);
  *param_1 = local_3c[0];
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  FUN_00412870(local_3c,0,0xffffffff);
  if (local_38 != (undefined1 *)0x0) {
    cVar1 = local_38[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_38 + -1);
    }
    else {
      local_38[-1] = cVar1 + -1;
    }
  }
  ExceptionList = local_c;
  return param_1;
}

