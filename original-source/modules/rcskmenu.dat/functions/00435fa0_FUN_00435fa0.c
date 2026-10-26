/*
 * FUN_00435fa0 at 00435fa0
 * undefined4 __register FUN_00435fa0(int param_1)
 * Address ranges: 00435fa0-00435fd0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00435fa0(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_0042687c(param_1);
  if (cVar1 != '\0') {
    iVar2 = FUN_0040303c(*(int **)(param_1 + 0x10),(int)&PTR_FUN_0042618c);
    if (*(short *)(iVar2 + 0x68) == *(short *)(*(int *)(param_1 + 0x18) + 0x54)) {
      return CONCAT31((int3)(CONCAT22((short)((uint)iVar2 >> 0x10),*(short *)(iVar2 + 0x68)) >> 8),1
                     );
    }
  }
  return 0;
}

