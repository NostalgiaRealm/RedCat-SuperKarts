/*
 * FUN_0042ff4c at 0042ff4c
 * undefined4 __register FUN_0042ff4c(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, int * param_7)
 * Address ranges: 0042ff4c-0042ff7a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4
FUN_0042ff4c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,int *param_7)

{
  int iVar1;
  
  iVar1 = FUN_00402e7c((int *)&DAT_0042909c,'\x01',param_3);
  *(undefined4 *)(iVar1 + 4) = param_4;
  *(int *)(iVar1 + 8) = param_7[2];
  iVar1 = FUN_0040f504(param_7,iVar1);
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}

