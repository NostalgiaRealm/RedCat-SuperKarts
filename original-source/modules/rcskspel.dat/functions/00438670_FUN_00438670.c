/*
 * FUN_00438670 at 00438670
 * undefined FUN_00438670(void)
 * Address ranges: 00438670-0043870d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00438670(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_1c [4];
  int local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd4e7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_004be6c9();
  uVar3 = FUN_004314a0(local_1c,iVar2 % 0xc + 9);
  local_4 = 0;
  FUN_00412710(param_1,&DAT_004ec1d0,uVar3);
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

