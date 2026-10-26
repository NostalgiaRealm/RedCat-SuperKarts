/*
 * FUN_0044defc at 0044defc
 * undefined4 __register FUN_0044defc(int * param_1)
 * Address ranges: 0044defc-0044df16
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0044defc(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x20))();
  (**(code **)(*param_1 + 0x14))(param_1,uVar1);
  return uVar1;
}

