/*
 * FUN_00482020 at 00482020
 * undefined FUN_00482020(void)
 * Address ranges: 00482020-00482183
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00482020(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  char cVar5;
  int *local_14;
  int *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d1368;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00484a70(&local_14);
  local_4 = 0;
  local_10 = (int *)*local_14;
  if (local_10 != (int *)0x0) {
    puVar1 = (undefined4 *)*local_10;
    while (puVar1 != (undefined4 *)0x0) {
      FUN_004afce0(s_updating_explosion_004f9a24);
      cVar5 = FUN_00483300(param_1);
      if (cVar5 == '\0') {
        iVar2 = puVar1[4];
        puVar3 = (undefined4 *)puVar1[3];
        if (iVar2 != 0) {
          *(undefined4 **)(iVar2 + 4) = puVar3;
        }
        if (puVar3 != (undefined4 *)0x0) {
          puVar3[2] = iVar2;
        }
        if (puVar1 + 2 == DAT_005450a0) {
          DAT_005450a0 = puVar3;
        }
        FUN_004827e0();
        *puVar1 = &PTR_FUN_004d2ebc;
        FUN_004827e0();
        FUN_004bc150(puVar1);
      }
      piVar4 = (int *)local_10[1];
      if (piVar4 == (int *)0x0) break;
      local_10 = piVar4;
      puVar1 = (undefined4 *)*piVar4;
    }
  }
  if (((DAT_005450a8 != (undefined4 *)0x0) && (cVar5 = FUN_00483300(param_1), cVar5 == '\0')) &&
     (DAT_005450a8 != (undefined4 *)0x0)) {
    FUN_004827e0();
    puVar1 = DAT_005450a8;
    if (DAT_005450a8 != (undefined4 *)0x0) {
      *DAT_005450a8 = &PTR_FUN_004d2ebc;
      FUN_004827e0();
      FUN_004bc150(puVar1);
    }
    DAT_005450a8 = (undefined4 *)0x0;
  }
  if (((DAT_005450a4 != (undefined4 *)0x0) && (cVar5 = FUN_00483300(param_1), cVar5 == '\0')) &&
     (DAT_005450a4 != (undefined4 *)0x0)) {
    FUN_004827e0();
    puVar1 = DAT_005450a4;
    if (DAT_005450a4 != (undefined4 *)0x0) {
      *DAT_005450a4 = &PTR_FUN_004d2ebc;
      FUN_004827e0();
      FUN_004bc150(puVar1);
    }
    DAT_005450a4 = (undefined4 *)0x0;
  }
  ExceptionList = local_c;
  return;
}

