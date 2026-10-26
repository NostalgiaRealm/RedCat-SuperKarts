/*
 * FUN_004ab460 at 004ab460
 * undefined FUN_004ab460(void)
 * Address ranges: 004ab460-004ab5b9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_004ab460(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d1888;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004af480(100);
  local_4 = 0;
  *(undefined4 *)(param_1 + 0x270) = param_2;
  if (DAT_004fe938 < 9) {
    *(undefined4 *)(param_1 + 0x278) = 4;
    *(undefined4 *)(param_1 + 0x2b0) = 1;
    uVar2 = 0xf2086b20;
    uVar3 = 0x11cf259f;
  }
  else {
    *(undefined4 *)(param_1 + 0x278) = 1;
    iVar1 = FUN_004ab370(0x84e63de0,0x11cf46aa,0x6f81,0x6e1520c0);
    if (iVar1 == 0) goto LAB_004ab57a;
    *(undefined4 *)(param_1 + 0x278) = 3;
    uVar2 = 0xa4665c60;
    uVar3 = 0x11cf2673;
  }
  iVar1 = FUN_004ab370(uVar2,uVar3,0xaa001aa3,0x5633b900);
  if (iVar1 != 0) {
    local_4 = 0xffffffff;
    FUN_004af680();
    ExceptionList = local_c;
    return 0;
  }
LAB_004ab57a:
  *(undefined4 *)(param_1 + 0x274) = 1;
  FUN_004ab700();
  FUN_004aaef0();
  local_4 = 0xffffffff;
  FUN_004af680();
  ExceptionList = local_c;
  return 1;
}

