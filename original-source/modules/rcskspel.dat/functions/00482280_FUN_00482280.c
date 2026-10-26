/*
 * FUN_00482280 at 00482280
 * undefined FUN_00482280(void)
 * Address ranges: 00482280-00482331
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00482280(void)

{
  undefined4 *puVar1;
  undefined1 local_14 [8];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d138c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00484a70(local_14);
  local_4 = 0;
  if (DAT_005450a8 != (undefined4 *)0x0) {
    FUN_004827e0();
    puVar1 = DAT_005450a8;
    if (DAT_005450a8 != (undefined4 *)0x0) {
      *DAT_005450a8 = &PTR_FUN_004d2ebc;
      FUN_004827e0();
      FUN_004bc150(puVar1);
    }
    DAT_005450a8 = (undefined4 *)0x0;
  }
  if (DAT_005450a4 != (undefined4 *)0x0) {
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

