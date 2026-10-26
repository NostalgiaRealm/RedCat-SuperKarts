/*
 * FUN_0047d400 at 0047d400
 * undefined FUN_0047d400(void)
 * Address ranges: 0047d400-0047d465
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0047d400(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d105b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x50);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0047d3d0(param_1,param_2,param_3);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}

