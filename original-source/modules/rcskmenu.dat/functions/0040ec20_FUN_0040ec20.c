/*
 * FUN_0040ec20 at 0040ec20
 * undefined4 __register FUN_0040ec20(int param_1)
 * Address ranges: 0040ec20-0040ec2a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040ec20(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + -0x38) != 0) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + -0x38) + 2);
  }
  return uVar1;
}

