/*
 * FUN_00437c40 at 00437c40
 * undefined FUN_00437c40(void)
 * Address ranges: 00437c40-00437cb3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00437c40(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 local_1c [4];
  int local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd40f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar2 = FUN_00437ff0(local_1c);
  local_4 = 0;
  FUN_00438760(uVar2);
  if (local_18 != 0) {
    cVar1 = *(char *)(local_18 + -1);
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      *(char *)(local_18 + -1) = cVar1 + -1;
      ExceptionList = local_c;
      return;
    }
    FUN_004bc150((char *)(local_18 + -1));
  }
  ExceptionList = local_c;
  return;
}

