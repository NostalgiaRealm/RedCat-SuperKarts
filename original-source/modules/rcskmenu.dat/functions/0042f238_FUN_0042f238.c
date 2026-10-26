/*
 * FUN_0042f238 at 0042f238
 * undefined4 __register FUN_0042f238(int * param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 0042f238-0042f264
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0042f238(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  if ((param_1 != (int *)0x0) &&
     (uVar1 = FUN_00403088(param_1,*(undefined4 *)(*(int *)(param_4 + -4) + 8),param_3),
     (char)uVar1 != '\0')) {
    return CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
  return 0;
}

