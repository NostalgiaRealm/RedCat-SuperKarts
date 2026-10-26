/*
 * FUN_0043d6f4 at 0043d6f4
 * undefined4 __register FUN_0043d6f4(void)
 * Address ranges: 0043d6f4-0043d786
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043d6f4(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  piVar1 = *(int **)(DAT_0047d7bc + 4);
  if ((((piVar1 != (int *)0x0) && ((char)piVar1[0x5f] != '\0')) && (piVar1[0x50] != 0)) &&
     (iVar2 = FUN_0044401c((int)piVar1), iVar2 != 0)) {
    iVar2 = FUN_0044401c((int)piVar1);
    if ((iVar2 == 1) &&
       (iVar2 = FUN_0040f6b0((undefined4 *)piVar1[0x50],0), iVar2 == *(int *)(DAT_0047d7bc + 0x38)))
    {
      return 0;
    }
    piVar3 = FUN_0043e0b0((POINT *)(DAT_0047d7bc + 0xc),0);
    while( true ) {
      if (piVar3 == (int *)0x0) {
        return 0;
      }
      if (piVar1 == piVar3) {
        return 0;
      }
      iVar2 = FUN_0040f70c(piVar1[0x50],(int)piVar3);
      if (iVar2 != -1) break;
      piVar3 = (int *)piVar3[9];
    }
    uVar4 = FUN_00444030((int)piVar1,iVar2);
  }
  return uVar4;
}

