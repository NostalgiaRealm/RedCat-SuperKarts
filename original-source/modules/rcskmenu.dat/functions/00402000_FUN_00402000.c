/*
 * FUN_00402000 at 00402000
 * undefined4 __register FUN_00402000(LPVOID param_1, int param_2)
 * Address ranges: 00402000-00402030
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00402000(LPVOID param_1,int param_2)

{
  undefined4 uVar1;
  uint local_10 [2];
  
  FUN_004018d0(param_1,param_2 + 4,(int *)local_10);
  if ((local_10[0] != 0) && (uVar1 = FUN_00401f48(local_10), (char)uVar1 != '\0')) {
    return CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
  return 0;
}

