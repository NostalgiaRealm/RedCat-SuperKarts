/*
 * FUN_00438760 at 00438760
 * undefined FUN_00438760(void)
 * Address ranges: 00438760-00438799
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00438760(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  FUN_004371f0();
  cVar1 = FUN_00438710();
  if (cVar1 != '\0') {
    uVar2 = FUN_00437ea0(DAT_00508610,param_1);
    FUN_004371f0(uVar2);
    FUN_00437b40(uVar2,param_1);
    return 1;
  }
  return 0;
}

