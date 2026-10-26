/*
 * FUN_00452630 at 00452630
 * undefined FUN_00452630(void)
 * Address ranges: 00452630-004526e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00452630(undefined4 *param_1)

{
  int iVar1;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004cdc68;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00452890(&local_10,*(undefined4 *)param_1[3],(undefined4 *)param_1[3]);
  FUN_004bc150(param_1[3]);
  param_1[3] = 0;
  param_1[5] = 0;
  DAT_00543d30 = DAT_00543d30 + -1;
  if (DAT_00543d30 == 0) {
    FUN_004bc150(DAT_00543d2c);
    DAT_00543d2c = 0;
  }
  iVar1 = param_1[1];
  *param_1 = &PTR_FUN_004d2798;
  if (iVar1 != 0) {
    local_10 = *(undefined4 *)(iVar1 + 4);
    FUN_004bc150(local_10);
    *(undefined4 *)(iVar1 + 4) = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    FUN_004bc150(iVar1);
  }
  param_1[1] = 0;
  ExceptionList = local_c;
  return;
}

