/*
 * FUN_0045043c at 0045043c
 * undefined __register FUN_0045043c(undefined4 * param_1, uint * param_2)
 * Address ranges: 0045043c-00450467
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045043c(undefined4 *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0x100;
  do {
    uVar1 = FUN_00450410(*param_1);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

