/*
 * FUN_004387e0 at 004387e0
 * undefined FUN_004387e0(void)
 * Address ranges: 004387e0-004388c6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004387e0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined1 local_2c [4];
  int local_28;
  undefined1 local_1c [4];
  int local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd501;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  cVar1 = FUN_00438730(param_2);
  if (cVar1 == '\0') {
    uVar2 = FUN_004381d0(local_1c);
    local_4 = 1;
    FUN_004387a0(param_1,uVar2);
    if (local_18 == 0) {
      ExceptionList = local_c;
      return;
    }
    pcVar4 = (char *)(local_18 + -1);
    cVar1 = *(char *)(local_18 + -1);
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      *pcVar4 = cVar1 + -1;
      ExceptionList = local_c;
      return;
    }
  }
  else {
    FUN_004371f0();
    uVar2 = FUN_00437ea0(param_2);
    uVar3 = FUN_00438130(local_2c);
    local_4 = 0;
    FUN_004371f0(uVar2,uVar3);
    FUN_00437b10(uVar2,uVar3);
    if (local_28 == 0) {
      ExceptionList = local_c;
      return;
    }
    pcVar4 = (char *)(local_28 + -1);
    cVar1 = *(char *)(local_28 + -1);
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      *pcVar4 = cVar1 + -1;
      ExceptionList = local_c;
      return;
    }
  }
  FUN_004bc150(pcVar4);
  ExceptionList = local_c;
  return;
}

