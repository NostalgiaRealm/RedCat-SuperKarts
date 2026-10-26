/*
 * FUN_004387a0 at 004387a0
 * undefined FUN_004387a0(void)
 * Address ranges: 004387a0-004387d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004387a0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = FUN_00438730(param_1);
  if (cVar1 != '\0') {
    uVar2 = FUN_00437ea0(param_1,param_2);
    FUN_004371f0(uVar2);
    FUN_00437b40(uVar2,param_2);
    return 1;
  }
  return 0;
}

