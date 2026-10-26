/*
 * FUN_00482190 at 00482190
 * undefined FUN_00482190(void)
 * Address ranges: 00482190-00482279
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00482190(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  int *local_14;
  undefined4 *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d137a;
  pvStack_c = ExceptionList;
  puStack_1c = (undefined1 *)&local_14;
  uStack_20 = 0x4821b8;
  ExceptionList = &pvStack_c;
  FUN_00484a70();
  local_4 = 0;
  local_10 = (undefined4 *)*local_14;
  if (local_10 == (undefined4 *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)*local_10;
  }
  puStack_1c = (undefined1 *)0x0;
  uStack_20 = 0xe;
  (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c);
  (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,1);
  if (DAT_005450a8 != (int *)0x0) {
    (**(code **)(*DAT_005450a8 + 0x10))(&local_14);
  }
  if (DAT_005450a4 != (int *)0x0) {
    (**(code **)(*DAT_005450a4 + 0x10))(&local_14);
  }
  puVar3 = (undefined4 *)0x1;
  piVar2 = DAT_006a621c;
  (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0xe);
  while (piVar1 != (int *)0x0) {
    FUN_004afce0(s_drawing_explosion_004f9a38);
    (**(code **)(*piVar1 + 0x10))(&uStack_20);
    puVar3 = (undefined4 *)puVar3[1];
    if (puVar3 == (undefined4 *)0x0) break;
    piVar1 = (int *)*puVar3;
  }
  (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,0);
  ExceptionList = piVar2;
  return;
}

