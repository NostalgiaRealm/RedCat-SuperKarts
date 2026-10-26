/*
 * FUN_00438130 at 00438130
 * undefined FUN_00438130(void)
 * Address ranges: 00438130-004381ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00438130(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 local_1c [4];
  int local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd469;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar2 = FUN_004be6c9();
  uVar2 = uVar2 & 0x80000001;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffffe) + 1;
  }
  uVar3 = FUN_004314a0(local_1c,uVar2);
  local_4 = 0;
  FUN_00412710(param_1,s_PASSING_004ec190,uVar3);
  if (local_18 != 0) {
    cVar1 = *(char *)(local_18 + -1);
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      *(char *)(local_18 + -1) = cVar1 + -1;
      ExceptionList = local_c;
      return param_1;
    }
    FUN_004bc150((char *)(local_18 + -1));
  }
  ExceptionList = local_c;
  return param_1;
}

