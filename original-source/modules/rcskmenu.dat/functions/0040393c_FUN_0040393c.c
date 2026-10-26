/*
 * FUN_0040393c at 0040393c
 * undefined __register FUN_0040393c(int * param_1)
 * Address ranges: 0040393c-00403957
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040393c(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  piVar2 = param_1 + 1;
  do {
    FUN_00405438(*(undefined4 **)piVar2[1],(int *)*piVar2);
    piVar2 = piVar2 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

