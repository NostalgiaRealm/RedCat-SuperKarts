/*
 * FUN_00438730 at 00438730
 * undefined FUN_00438730(void)
 * Address ranges: 00438730-0043875a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00438730(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  cVar1 = FUN_00417e90(param_1);
  if (cVar1 != '\0') {
    uVar2 = FUN_00438710();
    return uVar2;
  }
  iVar3 = FUN_004be6c9();
  return (uint)(iVar3 % 3 == 0);
}

