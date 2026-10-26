/*
 * FUN_00442380 at 00442380
 * undefined FUN_00442380(void)
 * Address ranges: 00442380-004423e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00442380(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar2 = DAT_0068021c;
  if (0 < DAT_00680220) {
    do {
      if ((*(int *)(DAT_00680b28 + 0xec + *piVar2 * 0x984) == 0xd) ||
         (*(int *)(DAT_00680b28 + *piVar2 * 0x984 + 0xf0) == 0xd)) {
        uVar1 = FUN_00493a20(iVar3 + -1);
        return uVar1;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < DAT_00680220);
  }
  return 0;
}

