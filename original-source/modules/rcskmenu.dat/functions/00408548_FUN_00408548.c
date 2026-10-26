/*
 * FUN_00408548 at 00408548
 * undefined4 __register FUN_00408548(char * param_1)
 * Address ranges: 00408548-00408571
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00408548(char *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (param_1 == (char *)0x0) {
    return 0;
  }
  iVar1 = FUN_00408340(param_1);
  piVar2 = FUN_00408528(iVar1 + 1U);
  uVar3 = FUN_0040836c(piVar2,(undefined4 *)param_1,iVar1 + 1U);
  return uVar3;
}

