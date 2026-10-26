/*
 * FUN_00450494 at 00450494
 * undefined __register FUN_00450494(undefined4 * param_1, uint * param_2)
 * Address ranges: 00450494-004504bf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00450494(undefined4 *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0x100;
  do {
    uVar1 = FUN_00450468(*param_1);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

